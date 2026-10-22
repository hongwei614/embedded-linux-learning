#include<stdio.h>
int main(){
	int a[2][3] = {{2, 3, 6}, {7, 9, 10}};
	int b[3][2];
	int n,i,j;
	for(i = 0;i < sizeof(a) / sizeof(a[0]);i++){
		for(j = 0;j < sizeof(a[0]) / sizeof(int);j++){
			b[j][i] = a[i][j];
		};
	};
	printf("the transposed matrix is:");
	for(i = 0;i < sizeof(b) / sizeof(b[0]);i++){
		putchar('\n');
		for(j = 0;j < sizeof(b[0]) / sizeof(int);j++){
			printf("%d ",b[i][j]);
		};
	};
	
	return 0;
}	
