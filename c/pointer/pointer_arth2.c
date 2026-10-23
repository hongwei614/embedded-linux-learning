#include<stdio.h>
int main(){
	int a[5] = {3, 8, 19, 2, 1};
	int *p = &a;
	int *q = &a;
	q = p + 2;
	printf("%ld\n",q - p);
	
	int i;
	for(i = 0;i < 5;i++){
		printf("%d ",*(p + i));
	};
	putchar('\n');
	return 0;
}
