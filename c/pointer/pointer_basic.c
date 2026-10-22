#include<stdio.h>
int main(){
	int a = 0;
	int *p = &a;
	printf("var's addr is %p\n",p);
	printf("var's addr is %p\n",&a);
	printf("pointer's addr is %p\n",&p);
	(*p)++;   //(*(&a))++;
	printf("var + 1 = %d\n",a);
	return 0;
}
