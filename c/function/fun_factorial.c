#include<stdio.h>

int factorial(int n);

int main(){
	int n;
	printf("input a number:");
	scanf("%d",&n);
	printf("%d!=%d\n",n,factorial(n));
	return 0;
}

int factorial(int n){
	int ret;
	if(n == 1){
		return 1;
	}
	
	return n * factorial(n-1);

}
