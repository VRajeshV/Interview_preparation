#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/types.h>
#include<linux/poll.h>
#include<linux/wait.h>
#include<linux/slab.h>
#include "./include/pavan_chrdev_ioctl.h"

#define MY_CHR_DEV_NAME "pavan_char_dev"
#define DEVICE_COUNT 4
#define MY_CLASS "pavan_class"
#define DRV_BUF_SIZE 4000

static DECLARE_WAIT_QUEUE_HEAD(my_wq); 
static DECLARE_WAIT_QUEUE_HEAD(my_rq); 

struct class * pavan_class;
struct cdev pavan_cdev[DEVICE_COUNT];
static char * drv_buf = NULL;

static unsigned long size_rem = DRV_BUF_SIZE;

static dev_t dev_num;

static int pvn_crdev_open(struct inode * inode, struct file *flip)
{
	pr_info("in %s...\n", __func__);

	if(!drv_buf)
	{
		drv_buf = kmalloc(DRV_BUF_SIZE, GFP_KERNEL);
		if(!drv_buf)
		{
			pr_info("error in allocating memory for my drv_buf\n");
			return -ENOMEM;
		}
	}
	return 0;
}
//we have to undone everything we did in open task
static int pvn_crdev_release(struct inode * inode, struct file * flip)
{
	pr_info("in %s...\n", __func__);

	if(drv_buf)
		kfree(drv_buf);
	return 0;
}

ssize_t pvn_crdev_write(struct file * flip, const char __user * buf, size_t count, loff_t * f_pos)
{
	unsigned long not_copied = 0;

	pr_info("in %s...\n", __func__);

	if(count < size_rem)
	{
		not_copied = copy_from_user(drv_buf, buf, count);
		*f_pos += count - not_copied;
		size_rem -= count;
		pr_info("data in kernel buffer now: %s", drv_buf);
	}
	else
	{
		pr_info("count exceeds drv buffer size");
		return -ENOMEM;
	}

	return (count - not_copied);
}

ssize_t pvn_crdev_read(struct file * flip, char __user * buf, size_t count, loff_t * f_pos)
{
	unsigned long not_copied = 0;

	pr_info("in %s...\n", __func__);
	
/*	if(count > (DRV_BUF_SIZE - *f_pos))
	{
		pr_info("trying to read more than file size\n");
		return -ENOMEM;
	}*/
	not_copied = copy_to_user(buf, drv_buf, count);	
	*f_pos += count - not_copied;
	
	return (count - not_copied);
}

loff_t pvn_crdev_llseek(struct file * flip, loff_t pos, int whence)
{
	loff_t newpos = 0;
	pr_info("in %s...\n", __func__);
	
	switch(whence)
	{
		case SEEK_SET:	newpos = pos;
				break;
		case SEEK_CUR: 	newpos = flip->f_pos + pos;
				break;
		case SEEK_END: 	newpos = DRV_BUF_SIZE + pos;
				break;
		default: return -EINVAL;
	}
	if(newpos < 0)
		return -EINVAL;
	flip->f_pos = newpos;
	
	return newpos;
}
//not implemented full pledgedly
static unsigned int pvn_crdev_poll(struct file * flip, poll_table * wait)
{
	unsigned int ret_mask = 0;
	pr_info("in %s...\n", __func__);
	//poll_wait(flip, &my_wq, wait);
	//poll_wait(flip, &my_rq, wait);

	return ret_mask;
}

static long pavan_crdev_ioctl(struct file * filep, unsigned int cmd, unsigned long arg)
{
	int i;
	long ret = 0;
	pr_info("in %s...\n", __func__);

	switch(cmd)
	{
		case ERASE_BUF:	if(drv_buf)
						{
							for(i = 0; i < DRV_BUF_SIZE; i++)
								drv_buf[i] = '\0';
							pr_info("data in the buffer %s\n", drv_buf);		
						}
						break;
		case GET_FILE_POS: *(int *)arg = (long)filep->f_pos;
						break;
		default: pr_info("invalid cmd");
				 return -ENOTTY;
	}

	return ret;
}

static const struct file_operations pvn_crdev_fops = {
	.owner = THIS_MODULE,
	.read = pvn_crdev_read,
	.write = pvn_crdev_write,
	.open = pvn_crdev_open,
	.release = pvn_crdev_release,
	.llseek = pvn_crdev_llseek,
	.poll = pvn_crdev_poll,
	.unlocked_ioctl = pavan_crdev_ioctl
};

static int __init my_driver_init(void)
{
	int i;
	dev_t curr_dev;
	pr_info("in %s...\n", __func__);
	
	//requesting kernel to allocate devices along with minor and major numbers
	alloc_chrdev_region(&dev_num, 0, DEVICE_COUNT, MY_CHR_DEV_NAME);
	//creating a class for our device
	pavan_class = class_create(THIS_MODULE, MY_CLASS);
	for(i = 0; i < DEVICE_COUNT; i++)
	{
		cdev_init(&pavan_cdev[i], &pvn_crdev_fops);
		pavan_cdev[i].owner = THIS_MODULE;
		curr_dev = MKDEV(MAJOR(dev_num), MINOR(dev_num) + i);
		cdev_add(&pavan_cdev[i], curr_dev, 1);
		device_create(pavan_class, NULL, curr_dev, NULL, MY_CHR_DEV_NAME "%d", i);
	}
	return 0;
}

static void __exit my_driver_exit(void)
{
	int i, major;
	dev_t mydev;
	pr_info("in %s...\n", __func__);
	
	major = MAJOR(dev_num);
	for(i = 0; i < DEVICE_COUNT; i++)
	{
		mydev = MKDEV(major, i);
		device_destroy(pavan_class, mydev);
		cdev_del(&pavan_cdev[i]);
	}
	class_destroy(pavan_class);
    unregister_chrdev_region(dev_num, DEVICE_COUNT);

}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_DESCRIPTION("Pavan's amazing char driver");
MODULE_AUTHOR("pavanbobba206@gmail.com");
MODULE_LICENSE("GPL");
