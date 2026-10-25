#include<stdio.h> 
void sort(int *a, int n); 
int main(){ 
	int a[10];
	int i;
	printf("input numbers:");
	for(i = 0;i < 10;i++){
		if(scanf("%d",&a[i]) != 1){
			printf("input is not a number!");
			return 1;
		};
	};
	sort(a, sizeof(a) / sizeof(int));
	for(i = 0;i < 10;i++){
		printf("%d,",a[i]);
	};
	putchar('\n');
	return 0;
}

void sort(int *a, int n){
	int m;
	int i,j;
	for(i = 0;i < n;i++){
		for(j = i + 1;j < n;j++){
			if(a[i] > a[j]){
				m = a[i];
				a[i] = a[j];
				a[j] = m;
			};
		};
	};

}
