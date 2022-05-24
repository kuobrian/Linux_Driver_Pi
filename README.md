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

// To run this example create a device file with:
$ sudo mknod /dev/mydevice c 64 0

$ dmesg | tail 
$ sudo rmmod dev_nr
```

# 03_read_write
Auto Device File creation & Read- Write-Callbacks
```
// To run this example create a device file with:
$ sudo mknod /dev/mydevice c 64 0

$ make
$ sudo insmod write_read.ko

// test
$ echo "This is a test" >> /dev/dummydriver
```

# 04_GPIO_driver
GPIO driver
```
// To run this example create a device file with:
$ sudo mknod /dev/mydevice c 64 0

$ make
$ sudo insmod gpio_driver.ko

// test
$ sudo chmod 666 /dev/my_gpio_driver
$ echo 1 >> /dev/my_gpio_driver
$ echo 0 >> /dev/my_gpio_driver
```