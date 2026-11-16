#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("没有传入参数，无法执行\n");
		return -1;
	}
	printf("%s跳转到了目标程序,当前的进程号为%d,父进程的进程号为%d\n",argv[1], getpid(), getppid());
	return 0;
}
