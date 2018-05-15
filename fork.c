#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void fork_example() {
    int x = 1;
    // child process because return value zero
    // as the processes are not identical and run as different ones concurrently
    // OS allocates different data and resources of monitoring their flow and execution
    // Child's output will be 2, and Parent's will be 0
    if(fork() == 0) {
        printf("Child has x = %d\n", ++x);
    } else {
        printf("Parent has x = %d\n", --x);
    }
    // parent process because return value non-zero
}

void fork_exercise1() {
    // How many child processes will be created?
    // n is a symbolic number, and answer should be with n
    // here it's given value to avoid compiling issues
    int n = 7;
    for(int i = 0; i < n; i++) {
        fork();
    }
}

void fork_exercise2() {
    // Predict the output
    int a = 0;
    if(fork() == 0) {
        a += 5;
        printf("%d %p\n", a, &a);
    } else {
        a -= 5;
        printf("%d %p\n", a, &a);
    }
}

void fork_exercise3() {
    // Predict the outputs
    fork();
    fork() && fork() || fork();
    fork();

    printf("forked \n");
}

int main(void) {
    // make two process which run same
    // program after this instruction
    //fork();
    //fork();
    //fork();
    // total number of processes is equivalent 2 ^ n, where n is fork() function calls count
    fork_example();

    return 0;
}