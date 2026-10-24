#include<stdio.h>
int main(){
	char ch[100] = "The ";
	char *p = "pig!";
	char *q = p;
	char *c = ch;
	while(*c != '\0'){
		c++;
	};
	printf("%p,%p\n",ch,c);
	while(*q != '\0'){
		*c = *q;
		c++;
		q++;
	};
	*c = '\0';
	printf("%s\n",ch);
	return 0;
}
