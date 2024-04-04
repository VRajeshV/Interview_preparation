obj-m := hello_world.o
#obj-m += wait_queue.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

all default:modules
install:modules_install

modules modules_install help clean:
	$(MAKE) -C $(KERNELDIR) M=$(shell pwd) $@
