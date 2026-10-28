#include<stdio.h>

struct abc{
	char b;
	char c;
	int a;
};
struct cfg{
	char b;
	int a;
	char c;
};
int main(){
	struct abc n;
	struct cfg m;
	n.a = 100;
	n.b = 'c';
	printf("n.a = %d,n.b = %c\n",n.a,n.b);
	printf("sizeof(n.a) = %ld ,sizeof(n.b) = %ld,sizeof(n) = %ld\n",
			sizeof(n.a),sizeof(n.b),sizeof(n));//Byte alignment
	printf("sizeof(abc) = %ld, sizeof(cfg) = %ld\n",sizeof(n),
			sizeof(m));

	return 0;
};
