#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	// 创建消息队列
	char *mq_name = "/mymq";
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 100;
	attr.mq_curmsgs = 0;

	mqd_t mqdes = mq_open(mq_name, O_RDWR | O_CREAT, 0644, &attr);
	if (mqdes == (mqd_t)-1)
	{
		perror("mq_open");
		return -1;
	}

	// 创建父子进程
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return -1;
	}
	if (pid == 0)
	{
		//子进程 消息队列接收端
		char recebuf[100];	
		 // 接受10次消息
                for(int i = 0; i < 10 ; i++)
                {
                        memset(recebuf, 0, 100);
                        struct timespec timeout;
                        // 获取当前时间
                        clock_gettime(CLOCK_REALTIME, &timeout);
                        // 允许最大等待时间10s
                        timeout.tv_sec += 10;
			//接收消息
                        if (mq_timedreceive(mqdes, recebuf, 100, 0, &timeout) == -1)
                        {
                                perror("mq_timedreceive");
                        }
			// 将接收到的消息打印到控制台
			printf("子进程：%s",recebuf);
		}
	}else
	{
		//父进程 消息队列发送端
		char sendbuf[100];
		// 发送10次消息
		for(int i = 0; i < 10 ; i++)
		{
			memset(sendbuf, 0, 100);
			sprintf(sendbuf, "父进程第%d次的发送消息.\n", i+1);
			struct timespec timeout;
			// 获取当前时间
			clock_gettime(CLOCK_REALTIME, &timeout);
			// 允许最大等待时间10s
			timeout.tv_sec += 10;

			if (mq_timedsend(mqdes, sendbuf, 100, 0, &timeout) == -1)
			{
				perror("mq_timedsend");
			}
			// 每次发送完成父进程休眠1s
			printf("父进程:第%d次发送完成，休眠1s\n",i+1);
			sleep(1);
		}
	}

	// 释放消息队列描述符，父子进程都需要执行
	mq_close(mqdes);
	// 释放消息队列，只需要执行一次
	if (pid > 0)
	{
		mq_unlink(mq_name);	
	}
	return 0;
}
