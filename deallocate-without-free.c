#include <stdio.h>
#include <stdlib.h>

// For checking memory leaks there is a nice tool called valgrind. Check out later on arch how to install and use it.

// Standard library function realloc() can be used to deallocate previously allocated memory.
// Below is function declaration of "realloc()" from "stdlib.h".

// void *realloc(void *ptr, size_t size);

// If "size" is zero, then call to realloc is equivalent to "free(ptr)". And if "ptr" is NULL
// and size is non-zero then call to realloc is equivalent to "malloc(size)".

// function with memory leak
void * func_with_mem_leak(void) {
    int *ptr = (int*)malloc(10);
    return ptr;
}

void * fix_mem_leak(void *ptr) {
    return realloc(ptr, 0); // this basically means "free(ptr)"
}

int main(void) {
    // to see memory leak, call func_with_mem_leak without fix_mem_leak().
    // You can use "valgrind --leak-check=full" to view the issue.
    fix_mem_leak(func_with_mem_leak());
    return 0;
}