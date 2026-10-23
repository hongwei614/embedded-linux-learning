#include<stdio.h>
int main(){
	int a[2][3] = {{2, 3, 4},{5, 6, 7}};
	int i,j;
	int *p = a;
	int column = sizeof(a[0]) / sizeof(int);
	int line = sizeof(a) / sizeof(a[0]);
	for(i = 0;i < line;i++){
		for(j = 0;j < column;j++){
			printf("%d ",p[i * column + j]);
		};
		putchar('\n');
	};
	for(i = 0;i < line * column;i++){
		printf("%d ",p[i]);
	};
	putchar('\n');
	return 0;
}
