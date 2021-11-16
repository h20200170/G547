/*
 *  userapp.c - the process to use ioctl's to control the kernel module
 *
 *  Until now we could have used cat for input and output.  But now
 *  we need to do ioctl's, which require writing our own process.
 */

/*
 * device specifics, such as ioctl numbers and the
 * major device file.
 */
#include "chardev.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>              /* open */
#include <unistd.h>             /* exit */
#include <sys/ioctl.h>          /* ioctl */
#include <string.h>

/*
 * Functions for the ioctl calls
 */

/*
int ioctl_set_msg(int file_desc, char *message)
{
    int ret_val;

    ret_val = ioctl(file_desc, IOCTL_SET_MSG, message);

    if (ret_val < 0) {
        printf("ioctl_set_msg failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
*/
int ioctl_get_msg(int file_desc)
{
    int ret_val;
    char message[3];

    ret_val = ioctl(file_desc, IOCTL_GET_MSG, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }

    printf("get_msg message:%s\n", message);
    return 0;
}


//function for ioctl call 1 - to get accelerometer x coordinate data 

int ioctl_get_acceleartor_x(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing accelerometer x axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_ACCELERATOR_X, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
    
    printf("Accelerator x coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 2 - to get accelerometer y coordinate data 
int ioctl_get_acceleartor_y(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing accelerometer y axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_ACCELERATOR_Y, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
  
    printf("Accelerator y coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 3 - to get accelerometer z coordinate data 
int ioctl_get_acceleartor_z(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing accelerometer z axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_ACCELERATOR_Z, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
  
    printf("Accelerator y coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 4 - to get gyroscope x coordinate data 
int ioctl_get_gyro_x(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing gyroscope x axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_GYRO_X, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
   
    printf("Gyro x coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 5 - to get gyroscope y coordinate data 
int ioctl_get_gyro_y(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing gyroscope y axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_GYRO_Y, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
    
    printf("Gyro y coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 6 - to get gyroscope z coordinate data 
int ioctl_get_gyro_z(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing gyroscope z axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_GYRO_Z, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
  
    printf("Gyro z coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 7 - to get magnetometer x coordinate data 
int ioctl_get_magn_x(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing magnetometer x axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_MAGN_X, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
   
    printf("Magne x coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 8 - to get magnetometer y coordinate data 
int ioctl_get_magn_y(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing magnetometer y axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_MAGN_Y, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
   
    printf("Magne y coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 9 - to get magnetometer z coordinate data 
int ioctl_get_magn_z(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing magnetometer z axis\n");
    ret_val = ioctl(file_desc, IOCTL_GET_PRESSURE, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
   
    printf("Magne z coordinates:%s\n", message);
    
    return 0;
}

//function for ioctl call 10 - to get data from pressure sensor 
int ioctl_get_pressure(int file_desc)
{
    int ret_val;
    char message[3];

  printf("testing pressure sensor\n");
    ret_val = ioctl(file_desc, IOCTL_GET_MAGN_Z, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
    
    printf("pressure sensor reading:%s\n", message);
    
    return 0;
}


//function for updating registers
int ioctl_update_reg(int file_desc, char *message)
{
    int ret_val;

    ret_val = ioctl(file_desc, IOCTL_UPDATE_REG, message);

    if (ret_val < 0) {
        printf("ioctl_set_msg failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}

/*
 * Main - Call the ioctl functions
 */
int main()
{
    int file_desc, ret_val;
    char *msg = "IOCTL CALL\n";

    file_desc = open(DEVICE_FILE_NAME, 0);
    if (file_desc < 0) {
        printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
        exit(-1);
    }

  //10 ioctl calls

   ioctl_get_msg(file_desc);
//to get data from accelerometer - 3 coordinates x,y,z
    ioctl_get_acceleartor_x(file_desc);
	ioctl_get_acceleartor_y(file_desc);
ioctl_get_acceleartor_z(file_desc);

//to get data from gyroscope - 3 coordinates x,y,z
ioctl_get_gyro_x(file_desc);
	ioctl_get_gyro_y(file_desc);
ioctl_get_gyro_z(file_desc);

//to get data from magnetometer - 3 coordinates x,y,z
ioctl_get_magn_x(file_desc);
	ioctl_get_magn_y(file_desc);
ioctl_get_magn_z(file_desc);

//to get data from pressure sensor - 3 coordinates x,y,z
ioctl_get_pressure(file_desc);

//to write or update value of sensor
ioctl_update_reg(file_desc,'9');		
    close(file_desc);
    return 0;
}
