#include<stdio.h>
int main(){
	int a[] = {1, 2, 3, 4, 5};
	int i;
	int *p = a;
	for(i = 0;i < sizeof(a) / sizeof(int);i++){
		printf("%d,%d,%d,%d\n",a[i],*p + i,*a + i,p[i]);
	};
	return 0;
}
