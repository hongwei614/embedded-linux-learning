#include<stdio.h>
int a2A(char a[]){
	int i = 0;
	int num = 0;
	while(a[i] != '\0'){
		if(a[i] >= 'a' && a[i] <= 'z'){
			num++;
			a[i] -=	32;
		};
		i++;
	};
	return num;
}
int main(){
	char a[100];
	int num;
	printf("input a string:");
	scanf("%s",a);
	num = a2A(a);
	printf("%d\n",num);
	printf("%s\n",a);
	return 0;
}
