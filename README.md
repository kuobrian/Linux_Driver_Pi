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
$ echo "This is a test" > /dev/dummydriver
```

# 04_GPIO_driver
GPIO driver
```
$ make
$ sudo insmod gpio_driver.ko

// test
$ sudo chmod 666 /dev/my_gpio_driver
$ echo 1 > /dev/my_gpio_driver
$ echo 0 > /dev/my_gpio_driver
```

# 05 LCD text display driver
LCD driver
```
$ make
$ sudo insmod lcd_driver.ko

// test
$ sudo chmod 666 /dev/lcd
$ echo "Hello " > /dev/lcd
$ echo "LCD Driver" > /dev/lcd
```

# 06 PWM Driver
PWM Driver
```
$ make
$ sudo insmod pwm_driver.ko

// test
$ sudo chmod 666 /dev/my_pwm_driver
$ echo a > /dev/my_pwm_driver
$ echo j > /dev/my_pwm_driver
```

# 11 gpio_irq
Using GPIO Interrupts in a Linux Kernel Module
```
$ make
$ sudo insmod gpio_irq.ko

$ dmesg | tail 
```

# 12 Parameters
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

# 13 IOCTL
IOCtl in a Linux Kernel Module
```
$ make
$ sudo insmod ioctl_example.ko
$ dmesg | tail

// To run this example create a device file with:
$ sudo mknod /dev/mydevice c 64 0
```

# 14 kernel threads
Threads in a Linux Kernel Module
```
$ make
$ sudo insmod kthread.ko
$ dmesg | tail
```

# 15 Sending Signals
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

# 16 Poll
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
# 17 waitqueue
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
# 18
```
```
# 19
```
```
# 20
```
```
# 21
```
```