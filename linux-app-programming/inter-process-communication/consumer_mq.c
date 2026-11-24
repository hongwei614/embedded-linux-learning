#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	// 创建消息队列
	char *mq_name = "/p2cmq";
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 100;
	attr.mq_curmsgs = 0;
	char readbuf[100];
	struct timespec timeout;

	mqd_t mqdes = mq_open(mq_name, O_RDWR| O_CREAT, 0644, &attr);
	if (mqdes == (mqd_t)-1)
	{
		perror("mq_open");
		return -1;
	}
	// 不断从消息队列中读取消息，并打印到控制台 
	while(1)
	{
		memset(readbuf, 0, 100) ;
		// 获取当前时间
                clock_gettime(CLOCK_REALTIME, &timeout);
               	// 允许最大等待时间10s
                timeout.tv_sec += 10;
		//接收消息
                if (mq_timedreceive(mqdes, readbuf, 100, 0, &timeout) == -1)
                {
                	perror("mq_timedreceive");
			continue;
                }
		if (readbuf[0] == EOF)
		{
			printf("EOF,exit...\n");
			break;
		}
		// 将接收到的消息打印到控制台
		printf("消费者：%s",readbuf);
	}
	// 释放消息队列描述符，父子进程都需要执行
	mq_close(mqdes);
	return 0;
}
