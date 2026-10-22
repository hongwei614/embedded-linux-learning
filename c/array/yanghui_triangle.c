#include<stdio.h>
int main(){
	int n;
	int i,j;
	printf("how many lines print?");
	scanf("%d",&n);
	int a[n][n];
	for(i = 0;i < n;i++){
		for(j = 0;j <= i;j++){
			if(j == 0 || j == i){
				a[i][j] = 1;
			}else{
				a[i][j] = a[i-1][j] + a[i-1][j-1];
			}; 
		};
	};
	for(i = 0;i < n;i++){
		for(j = 0;j <= i;j++){
			printf("%d ",a[i][j]);
		};
		putchar('\n');
	};
	return 0;
}
