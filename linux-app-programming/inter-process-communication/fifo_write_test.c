#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	int fd; 
	char *fifo_path = "/tmp/myfifo";
	if (mkfifo(fifo_path, 0644) < 0)
	{
		perror("mkfifo");
		//若创建过fifo直接使用
		if (errno != 17)
		{
		return -1;
		}
	}

	fd = open(fifo_path, O_WRONLY);
	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	char buff[100];
	ssize_t read_num;
	while(((read_num = read(STDIN_FILENO, buff, 100)) > 0))
	{
		write(fd, buff, read_num);
	}
	if (read_num < 0)
	{
		perror("read");
		close(fd);
		return -1;
	}
	printf("发送端口终止，进程结束\n");
	close(fd);
	if (unlink(fifo_path) < 0)
	{
		perror("unklink");
		return -1;
	}
	return 0;
}
