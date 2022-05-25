# Linux_Driver_Pi

## How to Run

### 01 simple_LKM
```
$ make
$ sudo insmod mymodule.ko
$ dmesg | tail 
$ sudo rmmod mymodule
```

### 02 dev_nr
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

### 03 read_write
Auto Device File creation & Read- Write-Callbacks
```
// To run this example create a device file with:
$ sudo mknod /dev/mydevice c 64 0

$ make
$ sudo insmod write_read.ko

# test
$ echo "This is a test" > /dev/dummydriver
```

### 04 gpio_driver
GPIO driver
```
$ make
$ sudo insmod gpio_driver.ko

// test
$ sudo chmod 666 /dev/my_gpio_driver
$ echo 1 > /dev/my_gpio_driver
$ echo 0 > /dev/my_gpio_driver
```

### 05 LCD_text_display_driver
LCD driver
```
$ make
$ sudo insmod lcd_driver.ko

// test
$ sudo chmod 666 /dev/lcd
$ echo "Hello " > /dev/lcd
$ echo "LCD Driver" > /dev/lcd
```

### 06 PWM_Driver
PWM Driver
```
$ make
$ sudo insmod pwm_driver.ko

// test
$ sudo chmod 666 /dev/my_pwm_driver
$ echo a > /dev/my_pwm_driver
$ echo j > /dev/my_pwm_driver
```

### 11 gpio_irq
Using GPIO Interrupts in a Linux Kernel Module
```
$ make
$ sudo insmod gpio_irq.ko
$ dmesg | tail 
```

### 12 parameters
Parameters for a Linux Kernel Module [ref.](http://www.makelinux.net/ldd3/chp-2-sect-8.shtml)
```
$ make
$ sudo insmod my_params.ko
$ dmesg | tail

// list kernel info
$ /sbin/modinfo my_params.ko

// test
$ sudo insmod my_params.ko device_name="dummy" gpio_nr=2
```

### 13 ioctl
IOCtl in a Linux Kernel Module
```
$ make
$ sudo insmod ioctl_example.ko
$ dmesg | tail

// To run this example create a device file with:
$ sudo mknod /dev/mydevice c 64 0
```

### 14 kernel_threads
Threads in a Linux Kernel Module
```
$ make
$ sudo insmod kthread.ko
$ dmesg | tail
```

### 15 sending_signals
Sending a signal from Kernel to Userspace
- add an ioctl command forregistering the userspace application to the kernel
- <linux/sched/signal.h> for signal sending and signal stuff
```
$ make
$ sudo insmod gpio_irq_signal.ko
$ dmesg | tail

// To run this example create a device file with:
$ sudo mknod /dev/irq_signal c 64 0
```

### 16 poll
The Poll callback in a Linux Kernel Module
- initialize gpio and interrupt
- offer a register a device number
- open the corresponding device file and ues the poll function to be notifiedw whenever pressing button
```
$ make
$ sudo insmod gpio_irq_poll.ko
$ dmesg | tail

// To run this example create a device file with:
$ sudo mknod /dev/irq_poll c 64 0
```

### 17 waitqueue
Waitqueues in a Linux Kernel Module
-  <linux/jiffies.h> using a function with a timeout
```
$ make
$ sudo insmod waitqueue.ko
$ dmesg | tail

// To run this example create a device file with:
$ sudo mknod /dev/dummy c 64 0
$ echo 10 > /dev/my_pwm_driver
$ echo 11 > /dev/my_pwm_driver
```

### 18 procfs
Create procfs entries from a Linux Kernel Module
- procfs stands for rpocess file system and it's a virtual file system on unix machine
- it's mounted to /proc
```
// look up cpu info
$ cat /proc/cpuinfo

$ make
$ sudo insmod procfs_test.ko
$ dmesg | tail

$ echo "Hello from userspace" > /proc/hello/dummy
$ cat /proc/hello/dummy | head -n 3
```

### 19 sysfs
Create sysfs entries from a Linux Kernel Module
- sys is another virtual file system
- access the hardware or buses
```
$ make
$ sudo insmod sysfs_test.ko
$ dmesg | tail

$ ls /sys/kernel/hello/dummy -al
$ echo "Hello from userspace" > /sys/kernel/hello/dummy
```

### 20 dt_probe
Parsing from the device tree in a Linux Kernel Module
- [Device Tree](https://events.static.linuxfound.org/sites/events/files/slides/petazzoni-device-tree-dummies.pdf)
```
$ sudo dtoverlay testoverlay.dtbo
$ sudo ls /proc/device-tree/my_device/
$ sudo cat /proc/device-tree/my_device/label
$ sudo cat /proc/device-tree/my_device/name

$ make
$ sudo insmod dt_probe.ko
$ dmesg | tail
```

### 21 dt_gpio
Device Tree GPIO Driver
- connect gpio 21 to raspberry pi
```
$ sudo dtoverlay testoverlay.dtbo
$ sudo ls /proc/device-tree/my_device/
$ sudo cat /proc/device-tree/my_device/label
$ sudo cat /proc/device-tree/my_device/name

$ make
$ sudo insmod dt_gpio.ko
$ dmesg | tail
$ echo 1 > /proc/my-led
$ echo 0 > /proc/my-led
```