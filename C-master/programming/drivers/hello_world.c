#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

static int myvar;
module_param(myvar, int, S_IRUGO);

static int helloworld_init(void)
{
	pr_info("Hello world init\n");
	return 0;
}

static void helloworld_exit(void)
{
	pr_info("end of the helloworld module\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_INFO(desc, "pavan's hello world module");
MODULE_AUTHOR("pavanbobba");
MODULE_LICENSE("GPL");
MODULE_ALIAS("my_new_module");
