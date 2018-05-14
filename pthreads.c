#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// this is for intptr_t type to clear the warning about
// varying integer type between systems (4 bytes in 32bit system and 8 bytes in 64bit system)
// as intptr_t has same size no matter on which system (4 bytes)
#include <stdint.h> 

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
// P.S. execution needs -lpthread flag to link it with pthread library

int globalVar = 0;

//function to be executed by all threads
void *myThreadFun(void *vargp) {
	// Store the value argument passed to this thread
	int myId = (intptr_t)vargp;

	// Let us create a static variable to observe its changes
	static int staticVar = 0;

	// Change global and static vars
	++staticVar; ++globalVar;
	
	// Print the argument, static and global variables
	printf("Thread ID: %d, Static: %d, Global: %d\n", myId, ++staticVar, ++globalVar);
	return NULL;
}

int main() {
	pthread_t thread_id;

	// Let us create three threads
	for (int i = 0; i < 3; i++) {
		pthread_create(&thread_id, NULL, myThreadFun, (void *)(intptr_t)i);
	}

	pthread_exit(NULL);
	exit(0);
}