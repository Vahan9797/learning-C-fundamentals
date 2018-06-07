#include <stdio.h>

// In C, like normal data pointers (int *, char *, etc), we can have pointers to functions.
// Following is a simple example that shows declaration and function call using function pointer.

void add(int a, int b) {
    printf("Addition is %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Subtraction is %d\n", a - b);
}

void multiply(int a, int b) {
    printf("Multiplication is %d\n", a * b);
}

// A normal function with an int parameter and void return type
void fun(int a) {
    printf("Value of a is %d\n", a);
}

/** @INTERESTING @FACTS */

// 1. Unlike normal pointers, a function pointer points to code, not data.
//    Typically a function pointer stores the start of executable code.

// 2. Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

// 3. A function’s name can also be used to get functions’ address.
//    For example, in the below program, we have removed address operator ‘&’ in assignment.
//    We have also changed function call by removing *, the program still works.

// 4. Like normal pointers, we can have an array of function pointers.
//    Function pointer can be used in place of switch case.
//    For example, in below program, user is asked for a choice between 0 and 2 to do different tasks.

// 5. Like normal data pointers, a function pointer can be passed as
//    an argument and can also be returned from a function.

// 6. Many object oriented features in C++ are implemented using function pointers in C.
//    For example virtual functions. Class methods are another example implemented using function pointers.

int main(void) {
    // fun_ptr1 is a pointer to function fun()
    void (*fun_ptr1)(int) = &fun;

    // This declaration also works, see Interesting facts 3
    void (*fun_ptr2)(int) = fun;

    // invoking fun() using fun_ptr1
    (*fun_ptr1)(10);

    // invoking fun() using fun_ptr2
    fun_ptr2(20);

    // For below operations see Interesting facts 4
    // fun_ptr_arr is an array of function pointers
    void (*fun_ptr_arr[])(int, int) = { add, subtract, multiply };
    unsigned int ch, a = 15, b = 10;

    printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply: ");
    scanf("%d", &ch);

    if(ch > 2) return 0;

    (*fun_ptr_arr[ch])(a, b);

    return 0;
}