#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		printf("创建子进程失败\n");
		return -1;
	}else if(pid == 0)
	{
		//子进程代码
		printf("现在在子进程中：父进程号%d，子进程号%d\n",getppid(),getpid());
		char *name = "子进程";
        	char *argv[] = {"/home/linux/embedded-linux-learning/linux-app-programming/process-test/target_exe", name, NULL};
        	char *envp[] = {NULL};
        	int R = execve(argv[0], argv, envp);
		if (R == -1)
        	{
                	printf("子进程跳转至目标程序失败\n");
                	return -1;
        	}
        	// 跳转成功后此处代码无效
	}else
	{
		sleep(1);// 防止父进程运行完成后销毁，父进程号显示错误
		printf("当前在父进程中：没有进行跳转，父进程号%d，子进程号%d\n",getpid(),pid);

	}
	return 0;
}
