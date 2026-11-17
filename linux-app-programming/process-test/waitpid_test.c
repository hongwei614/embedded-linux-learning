#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	// fork之前
	printf("创建子进程之前\n");

	pid_t pid = fork();
	if (pid < 0)
	{
		printf("创建子进程失败\n");
		return -1;
	}else if (pid == 0)
	{
		// 子进程代码
		printf("子进程%d,跳转到ping中，它的父进程是%d\n",getpid(), getppid());
		char *argv[] = {"/usr/bin/ping", "-c", "50", "www.baidu.com", NULL};
		char *envp[] = {NULL};
		int execR = execve(argv[0], argv, envp);
		if (execR < 0)
		{
			printf("子进程跳转到目标程序失败\n");
			return -1;
		}
	}else
	{
		// 父进程代码
		printf("父进程%d正在等待子进程%d运行\n",getpid(),pid);
		waitpid(pid, NULL, 0);
	}
	printf("父进程%d等待完成\n",getpid());
	return 0;
}
