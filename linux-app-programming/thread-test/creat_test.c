#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_LEN 1024

char *buf;

// 创建两个线程
//  (1) 从控制台读取字符存入到缓存中
//  (2) 从缓存中读取字符打印到控制台

// 线程(1)运行逻辑
void *thread_input(void *argv)
{
	int i = 0;
	while(1)
	{
		char c = fgetc(stdin); 
		if (c != 0 && c !='\n')
		{
			buf[i++] = c;
			if (i >= BUF_LEN)
			{
				i = 0;
			}
		}
	}	
}

// 线程(2)运行逻辑
void *thread_output(void *argv)
{
	int i = 0;
	while(1)
	{
		if (buf[i] != 0)
		{
			fputc(buf[i], stdout);
			// 由于stdout是行缓存，只有遇到换行才刷新，所以需要加换行
			fputc('\n', stdout);
			// 打印后清零
			buf[i++] = 0;
		}else
		{
			// 避免线程空转，缓存为空则休眠一秒
			sleep(1);
		}
	}
}

int main(void)
{
	buf = malloc(BUF_LEN);
	if (buf == NULL)
	{
		perror("malloc");
		return -1;
	}
	// 清零buf
	memset(buf , 0, BUF_LEN);

	pthread_t tid_input, tid_output;
	// 创建线程
	pthread_create(&tid_input, NULL, thread_input, NULL);
	pthread_create(&tid_output, NULL, thread_output, NULL);
	
	// 等待线程结束	
	pthread_join(tid_input, NULL);
	pthread_join(tid_output, NULL);

	free(buf);
	return 0;
}
