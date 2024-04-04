#include<linux/module.h>
#include<linux/i2c.h>
#include<linux/device.h>
#include<linux/mod_devicetable.h>

static int pavan_i2c_probe(struct i2c_client * client, const struct i2c_device_id * dev_id)
{
	pr_info("%s function called\n", __func__);	
	
	return 0;
}

static int pavan_i2c_remove(struct i2c_client * client)
{
	pr_info("%s function called\n", __func__);	
	
	return 0;
}

static const struct of_device_id pavan_device_match[] = {
	{ .compatible = "pavan_i2c_device" },
	{}
}; 

MODULE_DEVICE_TABLE(of, pavan_device_match);

static struct i2c_driver pavan_i2c_driver = {
	.probe = pavan_i2c_probe,
	.remove = pavan_i2c_remove,
	.driver = {
		.name = "pavan_i2c_slave_dev",
//		.name = THIS_MODULE,
		.of_match_table = of_match_ptr(pavan_device_match),		
	},
};

module_i2c_driver(pavan_i2c_driver);

MODULE_DESCRIPTION("pavan's i2c module");
MODULE_AUTHOR("pavanbobba206@gmail.com");
MODULE_LICENSE("GPL");
