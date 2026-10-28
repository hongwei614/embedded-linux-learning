#include<stdio.h>

union abc{
	char a;
	int b;
};
int main(){
	union abc n;
	n.a = 'c';
	printf("n.a = %c,n.b = %c\n",n.a,n.b);
	n.b = 0x3256;
	printf("n.a = 0x%d,n.b = 0x%d\n",n.a,n.b);
	return 0;
};

