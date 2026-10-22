#include<stdio.h>
int main(){
	int a[3][3] = {{2, 4, 7}, {6, 2, 5}, {3, 11, 9}};
	int max = 0,i,j;
	int max_line,max_column;
	for(i = 0;i < sizeof(a) / sizeof(a[0]);i++){
		for(j = 0;j < sizeof(a[0]) / sizeof(int);j++){
			if(a[i][j] > max){
				max = a[i][j];
				max_line = i;
				max_column = j;
			};
		};
	};
 	printf("max number is %d!\n",max);
	printf("max_line is %d,max_column is %d!\n",max_line,max_column);
	return 0;
}
