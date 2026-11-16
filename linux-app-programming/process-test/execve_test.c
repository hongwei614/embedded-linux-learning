#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *name = "进程直接";
	char *argv[] = {"/home/linux/embedded-linux-learning/linux-app-programming/process-test/target_exe", name, NULL};
	char *envp[] = {NULL};
	int R = execve(argv[0], argv, envp);
	if (R == -1)
	{
		printf("跳转至目标程序失败\n");
		return -1;
	}
	// 跳转成功后此处代码无效
	return 0;
}
