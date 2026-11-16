#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd = open("io.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("open:");
		return -1;
	}

	pid_t pid = fork();
	char buff[1024];
	if(pid == -1)
	{
		printf("创建子进程失败\n");
		return -1;
	}else if(pid == 0)
	{
		//子进程运行的代码
		strcpy(buff, "这是子进程写入的数据\n");
	}else
	{
		//父进程运行的代码
		sleep(1);
		strcpy(buff, "这是父进程写入的数据\n");
	}

	ssize_t writeR = write(fd, buff, strlen(buff));
	if (writeR == -1)
	{
		perror("write");
		close(fd);
		return -1;
	}

	if (pid == 0)
	{
		printf("子进程写入完毕，并关闭文件\n");
		close(fd);
	}else
	{
		printf("父进程写入完毕，并关闭文件\n");
		close(fd);
	}

	return 0;
}
