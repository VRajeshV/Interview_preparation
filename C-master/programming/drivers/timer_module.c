#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/timer.h>
#include <linux/init.h> 

static struct timer_list my_timer;
static int timer_val;

module_param(timer_val, int, S_IRUGO);

MODULE_PARM_DESC(timer_val, "time interval to fire the timer");

void my_timer_callback(struct timer_list *ptr)
{
	printk("%s called (%ld).\n", __func__, jiffies);
}

static int __init my_init(void)
{
	int ret;
	
	printk("my timer module loaded\n");
	timer_setup(&my_timer, my_timer_callback, 0);
	printk("set up timer to fire in %dms (%ld)\n", timer_val, jiffies);
	
	ret = mod_timer(&my_timer, jiffies + msecs_to_jiffies(timer_val));
	if(ret)
		printk("modifying timer failed\n");
	return 0;
}

static void __exit my_exit(void)
{
	int ret;
	printk("cleaning up the timer\n");
	ret = del_timer(&my_timer);
	if(ret)
		printk("timer not completed\n");
	printk("Timer module getting unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("setting and testing a timer");
MODULE_AUTHOR("pavan kumar bobba");
MODULE_LICENSE("GPL");
