#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h> 
// 创建两个线程tan与ran,从控制台输入消息，两个线程检查消息是否是发给自己，若是则返回copy并结束进程，若不是则继续等待消息。
// 该程序存在bug两个线程同时从同一个 stdin 调用 fgets 读消息，一行输入只会被其中一个线程读走，另一个线程根本看不到

//定义结果结构体
typedef struct Result
{
    char *p;
    int len;
} Result;

// 线程tan运行函数代码
void *tan_thread(void *argv)
{
	char read_R[100];
	Result *result = malloc(sizeof(Result));
	while(1)
	{
		fgets(read_R, 100, stdin);
		if (read_R[0] == *((char *)argv))
		{
			// 是发生给本线程的消息
			result->p = "copy";
			result->len = strlen(result->p);
			pthread_exit((void *)result);
		}else
		{
			// 不是发生给本线程的消息
			printf("线程tan还在等待你的消息\n");
		}
	}
}

// 线程ran的运行函数代码
void *ran_thread(void *argv)
{
        char read_R[100];
        Result *result = malloc(sizeof(Rsult));
        while(1)
        {
                fgets(read_R, 100, stdin);
                if (read_R[0] == *((char *)argv))
                {
                        // 是发生给本线程的消息
                        result->p = "copy";
                        result->len = strlen(result->p);
                        pthread_exit((void *)result);
                }else
                {
                        // 不是发生给本线程的消息
                        printf("线程ran还在等待你的消息\n");
                }
        }
}

int main(void)
{
	char tan_code = 't';
	char ran_code = 'r';
	Result *tan_result = NULL;
	Result *ran_result = NULL;
	// 线程号声明
	pthread_t tid_tan;
	pthread_t tid_ran;
	// 创建线程
	pthread_create(&tid_tan, NULL, tan_thread, &tan_code);
	pthread_create(&tid_ran, NULL, ran_thread, &ran_code);
	// 回收线程
	pthread_join(tid_tan, (void **)&tan_result);
	printf("tan回复了%s,字数%d\n",tan_result->p,tan_result->len);
	free(tan_result);
	pthread_join(tid_ran, (void **)&ran_result);
	printf("ran回复了%s,字数%d\n",ran_result->p,ran_result->len);
	free(ran_result);
	return 0;
}
