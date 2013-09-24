#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main()
{
	int fd, i;
	char buff[100];
	fd=open("/n/scratch/rd.txt",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
	if(fd!=-1)
	{
		printf("rd.txt opened with read and write access in wrapfs\n");

		if((i=write(fd,"hello,how are you",20))>0)
		{
			printf("written to the file\n");

		}
		else
			printf("write failed\n");
		lseek(fd,0L,0);
		if( (i =read(fd,buff,20)) > 0 )
		{
			printf("read from the file %s\n",buff);
		}
		else
		{

			perror("error while reading\n");
			
			return -1;
		}
		

		close(fd);
	}
	else
	{
		printf("error opening the file\n");
		return -1;
	}
	fd=open("/tmp/rd.txt",O_RDONLY,S_IREAD);
	if(fd!=-1)
	{
		printf("rd.txt opened with read and write access in underlying file system\n");
		
		if((i=read(fd,buff,20))>0)
		{
			printf("read from the underlying file %s\n",buff);
		}
		else
			printf("read failed\n");
		close(fd);
	}
	else
	{
		printf("error opening the file\n");
		return -1;
	}

	fd=open("/n/scratch/rd.txt",O_CREAT|O_TRUNC|O_RDONLY,S_IREAD);
	if(fd!=-1)
	{
		printf("The file is truncated\n");
		if((i=read(fd,buff,20))>0)
		{
			printf("read from the file %s\n",buff);
		}
	}
	
	exit(0);

}
