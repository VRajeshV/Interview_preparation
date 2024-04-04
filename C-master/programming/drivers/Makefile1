obj-m = hello_world.o
obj-m += wait_queue.o
obj-m += timer_module.o
obj-m += tasklet_module.o
obj-m += workqueue_module.o
obj-m += workqueue_dedicated_module.o
obj-m += pavan_char_drv.o
obj-m += pavan_i2c_slave_dev.o

KDIR=/lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
