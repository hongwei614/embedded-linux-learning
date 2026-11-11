#include <stdio.h>

int main(){
	//打开文件
	char *filename = "student.txt";	
	FILE *ioFile = fopen(filename, "r");
	if (ioFile == NULL)
	{
		printf("打开文件失败！\n");
	}
	else
	{
		printf("打开文件成功！\n");
	}	

	//读取文件
    /*
    FILE *__restrict __stream: 读取的文件
    char *__restrict __format: 读取的匹配表达式
    ...: 变长参数列表 用于接收匹配的数据
    return: 成功返回参数的个数  失败返回0 报错或结束返回EOF
    int fscanf (FILE *__restrict __stream,  const char *__restrict __format, ...)
    */
	char name[100];
	int age;
	int fscanfR = fscanf(ioFile, "%s %d",name,&age);
	while(fscanfR > 0 ){
		printf("成功返回的参数有%d个\n",fscanfR);
		printf("%s今年%d岁。\n",name,age);
		fscanfR = fscanf(ioFile, "%s %d",name,&age);
	}

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
