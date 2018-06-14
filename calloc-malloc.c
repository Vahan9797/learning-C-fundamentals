#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** The name @calloc and @malloc are library functions that
 *  allocate memory dynamically. It means that memory is allocated
 *  during runtime(execution of program) from heap segment. */

/** @INITIALIZATION
 * @malloc() allocates memory block of given size (in bytes) and
 * returns a pointer to the beginning of the block. malloc() doesn't
 * initialize the allocated memory. If we try to access the content
 * of memory block then we'll get garbage values.
 *
 * void * malloc(size_t size);
 *
 * @calloc() allocates the memory and also initializes the allocated
 * memory block to zero. If we try to access the content of these
 * blocks then we'll get 0.
 *
 * void * calloc(size_t num, size_t size);
 *
 * @NUMBER @OF @ARGUMENTS: Unlike malloc(), calloc() takes two arguments:
 * 1) Number of blocks to be allocated.
 * 2) Size of each block.
 *
 * @RETURN @VALUE If allocation succeeds, a pointer of memory is returned,
 * otherwise NULL is returned as a failure of allocation. */

int main(void) {
    // For instance, if we want to allocate memory for array of 5 integers:
    int *arr;
    // malloc() allocate the memory for 5 integers
    // containing garbage values
    arr = (int *)malloc(5 * sizeof(int)); // 5 * 4 bytes = 5 bytes
    printf("arr with malloc is %d\n", *arr);

    // De-allocates memory previously allocated by malloc() function
    free(arr);

    // calloc() allocate the memory for 5 integers and
    // set 0 to all of them
    arr = (int *)calloc(5, sizeof(int));
    printf("arr with calloc is %d\n", *arr);

    // De-allocates memory previously allocated by calloc() function
    free(arr);

    // We can achieve same functionality as calloc() by using malloc() followed by memset()
    int *ptr;
    ptr = malloc(sizeof(int));
    memset(ptr, 0, sizeof(int));

    return 0;
}