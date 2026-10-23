#include<stdio.h>
int main(){
	int a[] = {1, 2, 3, 4, 5};
	int i;
	printf("sizeof(a) = %ld\n",sizeof(a));
	for(i = 0;i < sizeof(a) / sizeof(int);i++){
		printf("the content is %d,the addr is %p\n ",*a + i,a + i);
	};
	putchar('\n');
	return 0;
}
