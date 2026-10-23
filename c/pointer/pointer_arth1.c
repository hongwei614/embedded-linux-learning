#include<stdio.h> 
int main(){
	int a = 10;
	int *p = &a;
	printf("int's pointer is %p\n",p);
	printf("int's pointer + 1 is %p\n",p + 1);
	printf("size of int is %ld\n",sizeof(int));
	
	char c = 'a';
	char *q = &c;
	printf("char's pointer is %p\n",q);
	printf("char's pointer + 1 is %p\n",q + 1);
	printf("size of char is %ld\n",sizeof(char));
	return 0;
}
