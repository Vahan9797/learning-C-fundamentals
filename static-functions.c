#include <stdio.h>

static int fun(void) {
    printf("Static functions in action!\n");
}

// Unlike global functions in C, access to static functions is restricted
// to the file where they are declared. Therefore, when we want to restrict
// access to functions, we make them static. Another reason for making
// functions static can be reuse of the same function name in other files.

int main(void) {
    fun();
    return 0;
}