
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


#define keylength 32

int main(int argc, char **argv)
{
	int fd;
	char key[keylength];
	memset(key,0,keylength);
	if(argc!=3)
	{
		printf("You have to give the value of the key and the mount point\n");
	}
	else
	{
		strncpy(key,argv[1],keylength);
		fd=open(argv[2],O_RDONLY);
		if(fd!=-1)
		{
			ioctl(fd,1,key);
			close(fd);
		}
		else
			printf("Device not found\n");
	}
	return 0;
}
