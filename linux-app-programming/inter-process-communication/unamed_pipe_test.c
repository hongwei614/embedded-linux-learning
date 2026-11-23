#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int pipefd[2];
	if (argc < 2)
	{
		printf("请输入参数！\n");
		exit(EXIT_FAILURE);
	}
	
	if (pipe(pipefd) == 0)
	{
		printf("创建管道成功！\n");
	}else
	{
		printf("创建管道失败！\n");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		printf("创建子进程失败!\n");
		exit(EXIT_FAILURE);
	}else if (pid == 0)
	{
		//子进程代码,从匿名管道中读取数据
		char buff;
		printf("子程序%d读取数据\n",getpid());
		close(pipefd[1]);
		printf("读取的数据为：");
		while(read(pipefd[0], &buff, sizeof(buff)))
		{
			printf("%c", buff);
		}
		close(pipefd[0]);
		putchar('\n');
	}else 
	{
		//父进程代码,向匿名管道管道中写入数据
		printf("父程序%d写入数据\n",getpid());
		close(pipefd[0]);
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]);
		waitpid(pid, NULL, 0);	
		exit(EXIT_SUCCESS);
	}
	return 0;
}
