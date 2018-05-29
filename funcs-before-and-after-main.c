#include <stdio.h>

// With GCC family of C compilers, we can mark some functions to execute before and after main().
// So some startup code can be executed before main() starts, and some cleanup code can be executed after main() ends.
// For example, in the following program, myStartupFun() is called before main() and myCleanupFun() is called after main().

// Apply the constructor attribute to myStartupFun() so that it is executed before main()
void myStartupFun(void) __attribute__ ((constructor));

// Apply the destructor attribute to myCleanupFun() so that it is executed after main()
void myCleanupFun(void) __attribute__ ((destructor));

int main(void) {
    printf("Main epta\n");
    return 0;
}

// implementation of myStartupFun
void myStartupFun(void) {
    printf("Startup code before main()\n");
}

// implementation of myCleanupFun
void myCleanupFun(void) {
    printf("Cleanup code after main()\n");
}