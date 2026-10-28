#include<stdio.h>

int main(){
	const int a = 10;
	//a = 20; error: assignment of read-only variable ‘a’
	printf("a = %d\n",a);
	return 0;
};
