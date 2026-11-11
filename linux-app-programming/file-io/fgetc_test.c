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

	//读取字符
    /*
    FILE *__stream: 需要读取的文件
    return： 读取的一个字节 到文件结尾或出错返回EOF
    int fgetc (FILE *__stream)
    */
	char c = fgetc(ioFile);
	while(c != EOF){
		printf("%c",c);
		c = fgetc(ioFile);//中文由多个字节组成，单个字节打印为乱码，当打印出多个字节时，系统会自动编码成中文
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
