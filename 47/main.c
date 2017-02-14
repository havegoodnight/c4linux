#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void handlethread(char *message);

int main(int argc, char *argv[]){
	pthread_t pthread1;
	pthread_t pthread2;

	char *massage1 = "Thread 1.";
	char *massage2 = "Thread 2.";

	int return1;
	int return2;

	return1 = pthread_create(&pthread1, NULL, (void *)handlethread, (char *)massage1);
	return2 = pthread_create(&pthread2, NULL, (void *)handlethread, (char *)massage2);


	printf("Create thread1 return : %d\n", return1);
	printf("Create thread2 return : %d\n", return2);

	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);

	return 0;
}

void handlethread(char *message){
	int i;
	for (i = 0; i < 16; i++) {
		printf("[%d] times : %s\n", i, message);
		sleep(1);
	}
}
