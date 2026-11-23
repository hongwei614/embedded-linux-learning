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

	fd = open(fifo_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	char buff[100];
	ssize_t read_num;
	while(((read_num = read(fd, buff, 100)) > 0))
	{
		write(STDOUT_FILENO, buff, read_num);
	}
	if (read_num < 0)
        {
                perror("read");
                close(fd);
                return -1;
        }
        printf("接收端口终止，进程结束\n");
	close(fd);
	return 0;
}
