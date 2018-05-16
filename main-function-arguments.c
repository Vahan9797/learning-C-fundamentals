#include <stdio.h>

void fun() { }
void fun_with_void(void) { }

int main(void) {
    fun(10, "GfG", "GQ"); // Compiles and runs fine in C, but not in C++
    //fun_with_void(10, "GfG", "GQ"); // Fails in compilation in both C and C++, uncomment to see the error, commented just to pass compilation
    return 0;
}

// Unlike C, in C++, both of the above programs fails in compilation.
// In C++, both fun() and fun(void) are same.

//  So the difference is, in C, int main() can be called with any number of arguments,
//  but int main(void) can only be called without any argument.

//  Although it does not make any difference most of the times,
//  using “int main(void)” is a recommended practice in C.

// Exercise:
// Predict output of following C programs.

// Question 1:
// int main() {
//     static int i = 5;
//     if (--i){
//         printf("%d ", i);
//         main(10);
//     }
// }
// Question 2:
// int main(void) {
//     static int i = 5;
//     if (--i){
//         printf("%d ", i);
//         main(10);
//     }
// }