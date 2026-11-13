#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd1,fd2;
	char buff[1024];
	char *filename1 = "io.txt";
	char *filename2 = "io1.txt";

	//打开文件	
	fd1 = open(filename1, O_RDONLY);
	if (fd1 == -1)
	{
		printf("文件io.text打开失败\n");
	}
	fd2 = open(filename2, O_RDWR | O_CREAT, 0644);
	if (fd1 == -1)
	{
		printf("文件io1.text打开失败\n");
	}
	
	//读取文件(fd1)
	ssize_t readR = read(fd1, buff, sizeof(buff));
	if (readR == -1)
	{
		printf("读取文件失败\n");
		exit(1);
	}else
	{
		printf("读取成功，读取到了%ld个字节\n", readR);
	}

	//使用标准输入打印读取的内容
	write(STDOUT_FILENO, buff, readR);
	putchar('\n');
	printf("printf:%s\n", buff);

	//写入文件(fd2)
	write(fd2, buff, readR);
	
	//关闭文件(fd1,fd2)
	close(fd1);
	close(fd2);
	return 0;
}
