#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER_SIZE 1024

int main(int argc,char **argv)
{
	int from_fd,to_fd;
	long file_len=0;
	int ret=1;
	char buffer[BUFFER_SIZE];

	/*判断参数个数*/
	if(argc!=3)
        {
		printf("Usage:%s fromfile tofile\n",argv[0]);
		exit(1);
	}
        /*打开源文件*/
        if((from_fd=open(argv[1],O_RDONLY|O_CREAT))==-1)
	{
		printf("Open %s Error\n",argv[1]);
		exit(1);
	}
	/*创建目的文件*/
        if((to_fd=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
        {
		printf("to_fd= %d",to_fd);
		printf("Open %s Error\n",argv[2]);
		exit(1);

	}
       

	/*进行文件拷贝*/
        while(1)
	{
		ret=read(from_fd,buffer,2);
		if(ret==-1)
		{
                    printf("read Error\n");
		    exit(1);
                 }
		if(ret==0)
		{
			printf("Copy Success \n");
			break;
		}
		else 
		{ 
		   int weRes=write(to_fd,buffer,ret);
		   if(weRes==-1)
		   {
			   printf("Write %s error\n",argv[2]);
			   exit(1);
		   }
          	}

	}
	close(from_fd);
	close(to_fd);
	exit(0);
}

       





