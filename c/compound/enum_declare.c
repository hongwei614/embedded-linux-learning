#include<stdio.h>

enum abc{
	A = 0,
	B = 1,
	C = 3,
	D
};
enum cfg{
	E = 0x123456789,
	F,
	G
};
int main(){
	printf("%d, %d, %d, %d\n",A, B, C, D);
	printf("sizeof A = %ld, sizeof abc = %ld\n",
			sizeof(A), sizeof(enum abc));
	printf("sizeof E = %ld, sizeof cfg = %ld\n",
			sizeof(E), sizeof(enum cfg));
	return 0;
}
