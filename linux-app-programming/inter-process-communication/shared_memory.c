#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	// 1 创建或打开共享内存对象
	char *memo_path = "/myshm";
	int fd = shm_open(memo_path, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("shm_open");
		return -1;
	}

	// 2 设定共享内存大小
	if (ftruncate(fd, 1024) == -1)
	{
		perror("ftruncate");
		return -1;
	}

	// 3 映射到进程地址空间
	char *memo_addr;
	memo_addr = mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	if (memo_addr == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}

	// 4 使用共享内存进行进程间通信
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return -1;
	}else if (pid == 0)
	{
		// 子进程
		printf("子进程从共享内存读取到的数据为：%s", memo_addr);
		close(fd);
	}else
	{
		//父进程
		strcpy(memo_addr, "一万年太久，只争朝夕！\n");
		printf("父进程向共享内存中写入数据\n");
		waitpid(pid, NULL, 0);
	        // 5 取消内存映射关系
        	if (munmap(memo_addr, 1024) == -1)
        	{
                	perror("munmap");
                	return -1;
        	}
	        // 6 删除共享内存对象
		close(fd);
        	if (shm_unlink(memo_path) == -1)
        	{
               		 perror("shm_unlink");
       		         return -1;
 	       	}
	}	

	return 0;
}
