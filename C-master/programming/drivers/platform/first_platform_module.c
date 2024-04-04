#include<linux/module.h>
#include<linux/platform_device.h>

//will get called only when device matches
static int my_platform_probe(struct platform_device *pdev)
{
	pr_info("in %s\n", __func__);
	return 0;
}

static int my_platform_remove(struct platform_device *pdev)
{
	pr_info("in %s\n", __func__);
	return 0;
}

static struct platform_driver my_drv = {
	.probe = my_platform_probe,
	.remove = my_platform_remove,
	.driver = {
		.name = KBUILD_MODNAME,
		.owner = THIS_MODULE,	
	},
};

static int __init my_platform_init(void)
{
	pr_info("in %s\n", __func__);

	platform_driver_register(&my_drv);
	return 0;
}

static void __exit my_platform_exit(void)
{
	pr_info("in %s\n", __func__);

	platform_driver_unregister(&my_drv);
}

module_init(my_platform_init);
module_exit(my_platform_exit);

MODULE_DESCRIPTION("pavan's first platform driver");
MODULE_AUTHOR("pavanbobba206@gmail.com");
MODULE_LICENSE("GPL");
