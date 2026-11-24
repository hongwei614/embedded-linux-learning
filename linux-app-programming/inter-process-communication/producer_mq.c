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
	char writebuf[100];
	struct timespec timeout;

	mqd_t mqdes = mq_open(mq_name, O_RDWR | O_CREAT, 0644, &attr);
	if (mqdes == (mqd_t)-1)
	{
		perror("mq_open");
		return -1;
	}
	// 不断从控制台中读取信息
	while(1)
	{
		memset(writebuf, 0, 100) ;
		ssize_t read_count = read(STDIN_FILENO, writebuf, 100); 
		if (read_count == -1)
		{
			perror("read");
			continue;
		}else if(read_count == 0)
		{
			// ctrl + D结束了循环
			printf("EOF,exit...\n");
			char eof = EOF;
			// 获取当前时间
			clock_gettime(CLOCK_REALTIME, &timeout);
			// 允许最大等待时间10s
			timeout.tv_sec += 10;
			mq_timedsend(mqdes, &eof, 1, 0, &timeout);
			break;
		}
                // 获取当前时间
                clock_gettime(CLOCK_REALTIME, &timeout);
              	// 允许最大等待时间10s
                timeout.tv_sec += 10;
               	if (mq_timedsend(mqdes, writebuf, strlen(writebuf), 0, &timeout) == -1)
		{
			perror("timedsend");
			break;
		}
	}
	// 释放消息队列描述符，父子进程都需要执行
	mq_close(mqdes);
	// 释放消息队列，只需要执行一次
	mq_unlink(mq_name);
	return 0;
}
