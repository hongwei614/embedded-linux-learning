#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("父进程的进程号为%d.\n",getpid());
	pid_t pid = fork();
	// 从这里开始，父进程与子进程同时运行
	if (pid < 0)
	{
		// 创建新进程失败
		printf("创建子进程失败！\n");
		return -1;
	}else if(pid == 0)
	{
		printf("子进程中：创建子进程成功，父进程号%d，子进程号%d\n",getppid(),getpid());
	}else
	{
		printf("父进程中：创建子进程成功，父进程号%d，子进程号%d\n",getpid(),pid);
	}
	
	return 0;
}
