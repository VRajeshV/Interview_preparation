#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/slab.h>
#include<linux/wait.h>
#include<linux/sched.h>
#include<linux/delay.h>
//#include<errno-base.h>
#include<linux/workqueue.h>

//static DECLARE_WAIT_QUEUE_HEAD(my_wq);
static int sleep = 0;

struct my_module_data{
	struct work_struct my_work;
	wait_queue_head_t my_wq;
	int the_data;
};

static void my_work_handler(struct work_struct * work_queue_ptr)
{
       struct my_module_data * data = container_of(work_queue_ptr, struct my_module_data, my_work);
	printk("in %s and data is %d\n", __FUNCTION__, data->the_data);
	msleep(2000);
	sleep = 1;
	wake_up_interruptible(&data->my_wq);
	kfree(data);
}

static int __init my_init(void)
{
	int ret = 0;
	struct my_module_data * my_module_data_ptr = NULL;
	printk("work queue module got loaded\n");

	my_module_data_ptr = kmalloc(sizeof(struct my_module_data), GFP_KERNEL);
	if(!my_module_data_ptr)
	{
		ret = -1;	
		goto err;
	}
	my_module_data_ptr->the_data = 60;
	INIT_WORK(&my_module_data_ptr->my_work, my_work_handler);
	init_waitqueue_head(&my_module_data_ptr->my_wq);	

	schedule_work(&my_module_data_ptr->my_work);
	wait_event_interruptible(my_module_data_ptr->my_wq, sleep != 0);
	printk("i got woken up\n");
	return 0;
	err:
		return ret;
}

static void __exit my_exit(void)
{
	printk("my work queue module getting exited\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("module to check work queue functionality");
MODULE_AUTHOR("pavan kumar bobba");
MODULE_LICENSE("GPL");
