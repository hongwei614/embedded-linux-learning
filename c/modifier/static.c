#include<stdio.h>

int func(void){
	static int b = 10;

	b++;
	
	return b;
}
int main(){
	printf("b = %d\n",func());
	printf("b = %d\n",func());
	return 0;
}
