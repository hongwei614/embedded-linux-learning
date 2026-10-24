#include<stdio.h>
int main(){
	int a[2][3] = {{3,7,9},
			{2,5,1}};
	int i;
	int row = sizeof(a) / sizeof(a[0]);
	int column = sizeof(a[0]) / sizeof(int);
	int n = row * column;
	int *p[n];
	for(i = 0;i < n;i++){
		p[i] = a[0] + i;
	};
	for(i = 0;i < n;i++){
		printf("%p\n",p[i]);
	};
	return 0;
}
