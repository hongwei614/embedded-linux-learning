#include<stdio.h>
int main(){
	char *ps[5] = {"apple", "banana", "orage", "pear", "pear"};
	char **q = ps;
	printf("%p,%p,%p\n",ps,&ps[0],q);
	printf("%s,%s,%s\n",*(ps + 1),ps[1],*(q + 1));

	return 0;
}
