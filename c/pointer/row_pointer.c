#include<stdio.h>
int main(){
	int a[3][4] = {{1, 2, 3, 4},{5, 6, 6, 7},{8, 9, 10, 9}};
	int (*p)[4] = a;
	int i,j;
	int row = sizeof(a) / sizeof(a[0]);
	int column = sizeof(a[0]) / sizeof(int);
	for(i = 0;i < row;i++){
		for(j = 0;j < column;j++){
			//printf("%d ",a[i][j]);       //element
			//printf("%d ",*(a[i] + j));   //element
			//printf("%p ",*(a + i) + j);  //address
			//printf("%d ",*(*(a + i) + j));  //element
			printf("%d ",*(*(p + i) + j));  //element
		};
		printf("\n");
	};
	return 0;
}
