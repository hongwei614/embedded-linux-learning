#include <stdio.h>

int main(){
	//打开文件
	char *filename = "io.txt";	
	FILE *ioFile = fopen(filename, "r");
	if (ioFile == NULL)
	{
		printf("打开文件失败！\n");
	}
	else
	{
		printf("打开文件成功！\n");
	}	

	//读取字符串
    /*
    char *__restrict __s: 接收读取的数据字符串
    int __n: 能够接收数据的长度
    FILE *__restrict __stream: 需要读取的文件
    return: 成功返回字符串 失败返回NULL(可以直接用于while)
    fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
    */
	char buff[100];
	printf("sizeof(buff) = %ld\n",sizeof(buff));
	while(fgets(buff, sizeof(buff), ioFile)){
		printf("%s",buff);
	}
	putchar('\n');

	//关闭文件
	int closeR = fclose(ioFile);
	if (closeR == EOF)
	{
		printf("关闭文件失败！\n");
	}
	else
	{
		printf("关闭文件成功！\n");
	}

	return 0;
}
