/* To compile the code with optimization, use -O option */
/* Also you may use --save-temps option for assembly, object and preprocessed files */
#include <stdio.h>

int main(void) {
    // VOLATILES -->

    // The volatile keyword is intended to prevent the compiler from applying
    // any optimizations on objects that can change in ways that cannot be
    // determined by the compiler.
    // Move volatile keyword and recompile the program to see the result
    const volatile int local = 10;
    int *ptr = (int*) &local;

    printf("Initial value of local: %d \n", local);

    *ptr = 100;

    printf("Modified value of local: %d \n", local);
    // <--

    // REGISTERS -->

    // The program below will not compile, as there is a request for address
    // of register variable, and you can't access their memory location ->
    register int i = 10;
    int *a = &i; // <- this line will cause error, comment this and printf to see through other stuff
    printf("%d", *a);
    // <-

    // But this code will compile successfully, as storing memory location in
    // register is completely fine ->
    int i1 = 10;
    register int *a1 = &i1;
    printf("%d", *a1);
    // <-

    // Register is a storage class, and C doesn't allow multiple storage classes
    // for a variable, so this code down below will cause error as well ->
    int i2 = 10;
    register static int *a2 = &i2; // <- comment this line and printf to compile
    printf("%d", *a2);
    // <-

    getchar();
    // <--

    return 0;
}