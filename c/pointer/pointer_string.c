#include<stdio.h>
int main(){
	char str[] = "Hello World!";
	char *p = str;
	while(*p != '\0'){
		if(*p >= 'A' && *p <= 'Z'){
			*p  += 32;
		}else if(*p >= 'a' && *p <='z'){ 
			*p -= 32;
		};
		p++;
	};
	printf("%s\n",str);
	return 0;
}
