#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

volatile int wait = 1; //int wait = 1;infinite loop

void* function(void* arg){
	while(1){
		sleep(1);
		wait = 0;
		printf("flag wait = %d in thread \n", wait);
	}
	return NULL;
}
int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, function, NULL);
	
	while(wait);
	printf("flag wait = %d in main \n", wait);
	return 0;
}
