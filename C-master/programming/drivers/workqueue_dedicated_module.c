#include<linux/init.h>
#include<linux/module.h>
#include<linux/workqueue.h>
#include<linux/slab.h>

struct workqueue_struct *wq;

struct work_data{
	struct work_struct my_work;
	int the_data;
};

static void work_handler(struct work_struct *work_wq)
{
	struct work_data * ptr = container_of(work_wq, struct work_data, my_work);
        printk("work queue module handler:%s , data is %d\n", __func__, ptr->the_data);
	kfree(ptr);
}

static int __init my_init(void)
{
	struct work_data *my_data;
	
	printk("work queue module init funcion: %s %d\n", __func__, __LINE__);
	wq = create_singlethread_workqueue("my_single_thread_queue");
	my_data = kmalloc(sizeof(struct work_data), GFP_KERNEL);
	my_data->the_data = 30;
	INIT_WORK(&my_data->my_work, work_handler);
	queue_work(wq, &my_data->my_work);
	return 0;
}

static void __exit my_exit(void)
{
	flush_workqueue(wq);
	destroy_workqueue(wq);
	printk("workqueue_dedicated module exiting\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("pavan's dedicated work queue module");
MODULE_AUTHOR("pavan bobba");
MODULE_LICENSE("GPL");
