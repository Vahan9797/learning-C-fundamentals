#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // When sizeof() is used with the data types such as int, float, char…
    // etc it simply return amount of memory is allocated to that data types.
    printf("Char: %lu\n", sizeof(char));
    printf("Int: %lu\n", sizeof(int));
    printf("Float: %lu\n", sizeof(float));
    printf("Double: %lu\n", sizeof(double));

    // When sizeof() is used with the expression, it returns size of the expression.
    // Let see example:
    int a = 0;
    double d = 10.21;
    printf("Int + Double: %lu\n", sizeof(a+d));

    // Sizeof can be used to calculate number of elements of the array automatically.
    // Let see Example:
    int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14};
    printf("Number of elements in arr: %lu\n", sizeof(arr)/ sizeof(arr[0]));

    // sizeof is greatly used in dynamic memory allocation. For example, if we want to
    // allocate memory for which is sufficient to hold 10 integers and we don’t know the
    // sizeof(int) in that particular machine. We can allocate with the help of sizeof.
    int *ptr = malloc(10*sizeof(int));

    // Print the dynamically allocated size. For different machines value might differ.
    printf("Dynamically allocated memory size of ptr: %lu\nThe pointer value: %p\nThe pointer: %d\n", sizeof(ptr), ptr, *ptr);

    // Free memory in the end
    free(ptr);

    return 0;
}