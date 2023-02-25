#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/intit.h>

MODULE_LICENSE( GPL");
MODULE_AUTHOR( "Futurist”);
MODULE_DESCRIPTION( "Myrzakhanov Abylaykhan, Tuleshev Turan, Turan Miras");

static char *name;

static int myInt = 0;

static int myArr[2] = {1, -1};
static int myArrCnt = 2;

module_param(name, charp, 0644);
MODULE_PARM_DESC(name, “Name of person:’);
module_param(myInt, int, 0644);
MODULE_PARM_DESC(myInt, "An Integer to print:");
module_param_array(myArr, int, &myArrCnt, 0644);

static int __init start(void){
        printk(KERN_INFO "Hello, %s! \n", name);
        printk(KERN_INFO “Value of Integer is: %d \n", myInt);
        return 0;

}

static void __exit stop(void) {
        printk(KERN_INFO “Stoping...");

}

module_init(start);
module_exit(stop);