#include<stdio.h>
int main(){
	int a[5] = {6, 7, 8, 9, 5};
	int *p = &a[0];
	printf("before: %d,addr: %p\n",*p,p);
	*p++;
	printf("after: %d,addr: %p\n",*p,p);
	return 0;
}
