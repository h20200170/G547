/*
 *  chardev2.h - the header file with the ioctl definitions.
 *
 *  The declarations here have to be in a header file, because
 *  they need to be known both to the kernel module
 *  (in chardev.c) and the process calling ioctl (ioctl.c)
 */

#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/ioctl.h>

/*
 * The major device number. We can't rely on dynamic
 * registration any more, because ioctls need to know
 * it.
 */
#define MAJOR_NUM 100

/*
 * Set the message of the device driver
 */
#define IOCTL_SET_MSG _IOR(MAJOR_NUM, 0, char *)
/*
 * _IOR means that we're creating an ioctl command
 * number for passing information from a user process
 * to the kernel module.
 *
 * The first arguments, MAJOR_NUM, is the major device
 * number we're using.
 *
 * The second argument is the number of the command
 * (there could be several with different meanings).
 *
 * The third argument is the type we want to get from
 * the process to the kernel.
 */


#define IOCTL_GET_MSG _IOR(MAJOR_NUM, 1, char *)

//IOCTL CALLS FOR ACCELEROMETER 3 AXIS - X,Y,Z


#define IOCTL_GET_ACCELERATOR_X _IOR(MAJOR_NUM, 3, char *)

#define IOCTL_GET_ACCELERATOR_Y _IOR(MAJOR_NUM, 4, char *)

#define IOCTL_GET_ACCELERATOR_Z _IOR(MAJOR_NUM, 5, char *)
//IOCTL CALLS FOR GYROSCOPE 3 AXIS - X,Y,Z
#define IOCTL_GET_GYRO_X _IOR(MAJOR_NUM, 6, char *)

#define IOCTL_GET_GYRO_Y _IOR(MAJOR_NUM, 7, char *)

#define IOCTL_GET_GYRO_Z _IOR(MAJOR_NUM, 8, char *)
//IOCTL CALLS FOR MAGNETOMETER 3 AXIS - X,Y,Z
#define IOCTL_GET_MAGN_X _IOR(MAJOR_NUM, 9, char *)

#define IOCTL_GET_MAGN_Y _IOR(MAJOR_NUM, 10, char *)

#define IOCTL_GET_MAGN_Z _IOR(MAJOR_NUM, 11, char *)
//IOCTL CALL FOR PRESSURE SENSOR
#define IOCTL_GET_PRESSURE _IOR(MAJOR_NUM, 12, char *)

#define IOCTL_UPDATE_REG _IOW(MAJOR_NUM, 13, char *)
/*
 * The name of the device file
 */
#define DEVICE_FILE_NAME "/dev/imu_char"


#endif
