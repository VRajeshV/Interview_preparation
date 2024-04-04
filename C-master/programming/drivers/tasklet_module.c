#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/interrupt.h>

static char tasklet_data[] = "my data to print in tasklet";

void my_tasklet_work(unsigned long data)
{
	printk("%s\n", tasklet_data);
}

DECLARE_TASKLET(my_tasklet, my_tasklet_work, (unsigned long)tasklet_data);

static int __init my_init(void)
{
	printk("my tasklet module got loaded\n");
	tasklet_schedule(&my_tasklet);
	return 0;
}

static void __exit my_exit(void)
{
	tasklet_kill(&my_tasklet);
	printk("tasklet module got unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("module to test tasklet functionality");
MODULE_AUTHOR("pavan kumar bobba");
MODULE_LICENSE("GPL");
