#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/workqueue.h>
#include<linux/delay.h>
#include <linux/init.h> 
#include <linux/sched.h> 
#include <linux/time.h> 

static DECLARE_WAIT_QUEUE_HEAD(my_wq);
static int my_cond = 0;

static struct work_struct wrk_q;

static void my_workqueue_handler(struct work_struct * work )
{
	printk("waitqueue module handler %s\n", __func__);
	msleep(5000);
	printk("waking up the sleeping module\n");
	my_cond = 1;
	wake_up_interruptible(&my_wq);
}
static int __init my_init(void)
{
	printk("my module with work queue\n");
	INIT_WORK(&wrk_q, my_workqueue_handler);
	schedule_work(&wrk_q);
	printk("going to sleep mode %s\n", __func__);
	wait_event_interruptible(my_wq, my_cond != 0);
	pr_info("waking up after the signal\n");
	return 0;
}

static void __exit my_exit(void)
{
	printk("cleaning up\n");
}

module_init(my_init);
module_exit(my_exit);

//MODULE_DESCRIPTION("putting a process into wait queue");
MODULE_AUTHOR("pavan kumar bobba");
MODULE_LICENSE("GPL");
