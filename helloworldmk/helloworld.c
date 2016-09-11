#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BEN QIN");
MODULE_DESCRIPTION("Hello world module");
MODULE_ALIAS("a simple module");

static char *name = "Ben Qin";
static int age = 29;

module_param(age, int, S_IRUGO);
module_param(name, charp, S_IRUGO);

static int hello_init(void)
{
    printk(KERN_WARNING"Hello, world!\n");
    //printk(KERN_WARNING"Hello, world!\n");
    printk(KERN_EMERG "Name:%s\n", name);
    printk(KERN_EMERG "Age:%d\n", age);
    return 0;
}


static void hello_exit(void)
{
    printk(KERN_INFO"Goodbye, world\n");
}


module_init(hello_init);
module_exit(hello_exit);
