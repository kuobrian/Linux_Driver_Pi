# Linux_Driver_Pi

### How to Run

## 01_simple_LKM
```
$ make
$ sudo insmod mymodule.ko
$ dmesg | tail 
$ sudo rmmod mymodule
```

## 02_dev_nr
Connect linux kernel module or device driver with device (over a device number)

- allocate or register major device number and minor device number
- write device file
- cat /proc/devices (devices and character devices)
```
$ make
$ sudo insmod dev_nr.ko
$ cat /proc/device | grep my_dev_nr
$ dmesg | tail 
$ sudo rmmod mymodule
```
To run this example create a device file with:
```
sudo mknod /dev/mydevice c 64 0
```