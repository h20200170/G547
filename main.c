/*
 *  chardev2.c - Create an input/output character device
 */

#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include <linux/kernel.h>       /* We're doing kernel work */
#include <linux/module.h>       /* Specifically, a module */
#include <linux/fs.h>
#include <asm/uaccess.h>        /* for get_user and put_user */
#include <linux/time.h>

#include "chardev.h"
#define SUCCESS 0
#define DEVICE_NAME "imu_char" //device name
#define BUF_LEN 80
static dev_t first;

static struct cdev c_dev;
static struct class *cls;
static int Device_Open = 0;
static char Message;
static char *Message_Ptr;



static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "device opened\n\n");    
    return SUCCESS;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "DEVICE RELEASED\n\n");
    return SUCCESS;
}


static ssize_t device_read(struct file *file,   
                           char __user * buffer,        
                                                        
                           size_t length,       
                           loff_t *offset)
{	
	int i;
//function sending 2 characters - 2 bytes
	char data[2];
        	data[0]=97;
        	data[1]=98;
        	for(i=0;i<3;i++)
        	{
        		put_user(data[i], data+i);
        	}

	//char a='5';
	printk(KERN_INFO "THIS IS DEVICE_READ\n\n");
	//put_user(a,buffer);
	return 0;

}

static ssize_t
device_write(struct file *file,
             const char __user * buffer, size_t length, loff_t * offset)
{
    
    get_user(Message, buffer);
	printk(KERN_INFO "message - data received from user space to kernel space %c\n\n",Message);
    return 0;
}


long device_ioctl(struct file *file,            
                  unsigned int ioctl_num,        
                  unsigned long ioctl_param)
{
    int i;
    char *temp;
    char ch;
    char char_acc;
//switch case statements to check ioctl call
    switch (ioctl_num) 
    {
    
    case IOCTL_GET_MSG:  
        device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('3',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
	

 case IOCTL_GET_ACCELERATOR_X:
	device_read(file, (char *)ioctl_param, 1, 0);
       // put_user('2',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
 case IOCTL_GET_ACCELERATOR_Y:
	device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('2',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
case IOCTL_GET_ACCELERATOR_Z:
	device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('2',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
case IOCTL_GET_GYRO_X:
	device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('3',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
 case IOCTL_GET_GYRO_Y:
	device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('3',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
        
        break;
case IOCTL_GET_GYRO_Z:
	device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('4',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
case IOCTL_GET_MAGN_X:
	device_read(file, (char *)ioctl_param, 1, 0);
        //put_user('4',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
 case IOCTL_GET_MAGN_Y:
	device_read(file, (char *)ioctl_param, 1, 0);
       // put_user('4',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;
case IOCTL_GET_MAGN_Z:
	device_read(file, (char *)ioctl_param, 1, 0);
       // put_user('5',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
        
        break;
case IOCTL_GET_PRESSURE:
	device_read(file, (char *)ioctl_param, 1, 0);
       // put_user('6',(char *)ioctl_param+1);
        put_user('\0', (char *)ioctl_param + 2);
       
        break;	
case IOCTL_UPDATE_REG:


         device_write(file, (char *)ioctl_param, 1, 0);
         break;

	
    }
    return SUCCESS;
}

struct file_operations fops = {
        .read = device_read,
        .write = device_write,
        .unlocked_ioctl = device_ioctl,
        .open = device_open,
        .release = device_release,      /* a.k.a. close */
};

/*
 * Initialize the module - Register the character device
 */
int init_char_module(void)
{
	printk(KERN_INFO "namaste: device registered\n\n");
	
	if(alloc_chrdev_region(&first, 0, 1, "BITS_PILANI")<0)
	{
		return -1;
	}
	
	if((cls=class_create(THIS_MODULE, "imu_char"))==NULL)
	{	
		unregister_chrdev_region(first, 1);
		return -1;
	}
	
	if(device_create(cls, NULL, first, NULL, "imu_char")==NULL)
	{
		class_destroy(cls);
		unregister_chrdev_region(first, 1);
		return -1;
	}
	
	cdev_init(&c_dev, &fops);
	if(cdev_add(&c_dev, first, 1)==-1)
	{
		device_destroy(cls, first);
		class_destroy(cls);
		unregister_chrdev_region(first, 1);
		return -1;
	}
	return 0;
	
}
static void exit_char_module(void)
{
cdev_del(&c_dev);
device_destroy(cls,first);
class_destroy(cls);
unregister_chrdev_region(first,1);
printk(KERN_INFO "my char unregistered \n\n");
}


module_init(init_char_module);
module_exit(exit_char_module);


MODULE_LICENSE("GPL");
