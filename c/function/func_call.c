#include<stdio.h>

//extern int printf (const char *__restrict __format, ...);
int (*p) (const char *__restrict__format, ...);
void func(void); 
int main(){

	func();

	return 0;	
}

void func(void){

	p = printf;
	p("func call\n");

}
