#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "ioctl_test.h"

int main() {
	int answer;
    struct mystruct test = {4, "Brian"};

    int dev = open("/dev/mydevice", O_WRONLY);
	if(dev == -1) {
		printf("Opening was not possible!\n");
		return -1;
	}
    
    ioctl(dev, RD_VALUE, &answer);
    printf("The answer is %d\n", answer);
    
    answer = 123;
    ioctl(dev, WR_VALUE, &answer);
    ioctl(dev, RD_VALUE, &answer);
    printf("The answer now is %d\n", answer);


    ioctl(dev, GREETER, &test);


	printf("Opening was Successful!\n");
	return 0;
}

