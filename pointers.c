#include <stdio.h>
#include <stdlib.h>

// See Dangling Pointer 2 part for function below
int *danglingFunctionCall() {
    // x is local variable and goes out of scope after execution of fun() is over
    // problem no longer occurs, when x becomes static
    static int x = 5; // <-- comment 'static' and see what happens

    return &x;
}

int main(void) {
    int var = 789;

    //pointer for var
    int *ptr2;

    // double pointer for ptr2
    int **ptr1;

    // storing pointer values
    ptr2 = &var;
    ptr1 = &ptr2;

    printf("Value of var = %d\n", var);
    printf("Value of var using single pointer = %d\n", *ptr2);
    printf("Value of var using double pointer = %d\n", **ptr1);

    /** @DANGLING @POINTER */

    // 1. De-allocation of memory

    // De-allocating a memory pointed by ptr causes dangling pointer
    int *ptr = (int *) malloc(sizeof(int));

    // After below free call, ptr becomes a dangling pointer
    free(ptr);

    // No more a dangling pointer
    ptr = NULL;

    // 2. Function Call

    // The pointer pointing to local variable becomes dangling when
    // local variable is static.
    int *p = danglingFunctionCall();
    fflush(stdin);

    // p points to something which is not valid anymore
    // this will print garbage address
    printf("%d\n", *p);

    // 3. Variable goes out of scope
    //    example:
    //    void main() {
    //        int *ptr;
    //        .....
    //        .....
    //        {
    //            int ch;
    //            ptr = &ch;
    //        }
    //        .....
    //        // Here ptr is dangling pointer
    //    }

    /** @VOID @POINTER */

    // Void pointer is a specific pointer type – void * – a pointer that points
    // to some data location in storage, which does not have any specific type.
    // Void refers to the type. Basically the type of data that it points to is can be any.

    /* IMPORTANT POINTS */
    // 1. void pointers cannot be de-referenced. It can however be done using typecasting the void pointer
    // 2. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.

    int a = 4;
    float b = 5.5;

    // A void pointer
    void *void_pointer;
    void_pointer = &a;

    // (int*)void_pointer - does type casting of void *((int*)ptr) dereferences
    // the typecasted void pointer variable.
    printf("Integer variable is = %d\n", *((int*) void_pointer));

    // void pointer is now float
    void_pointer = &b;
    printf("Float variable is = %f\n", *((float*) void_pointer));

    /** @NULL @POINTER */

    // NULL Pointer is a pointer which is pointing to nothing. In case, if we don’t
    // have address to be assigned to a pointer, then we can simply use NULL.

    /* IMPORTANT POINTS */
    // 1. NULL vs Uninitialized pointer – An uninitialized pointer stores an undefined value.
    // A null pointer stores a defined value, but one that is defined by the environment to
    // not be a valid address for any member or object.
    // 2. NULL vs Void Pointer – Null pointer is a value, while void pointer is a type

    int *null_ptr = NULL;

    printf("The value of null_ptr is %ls", null_ptr);

    /** @WILD @POINTER */

    // A pointer which has not been initialized to anything (not even NULL) is known as wild pointer.
    // The pointer may be initialized to a non-NULL garbage value that may not be a valid address.

    int *wild_pointer; /* wild pointer */

    int z = 10;

    // wild_pointer is not a wild pointer now
    wild_pointer = &z;

    return 0;
}