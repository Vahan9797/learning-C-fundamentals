#include <stdio.h>
#include <stdbool.h>

// Like Structures, union is a user defined data type.
// In union, all members share the same memory location.
// For example in the following C program, both x and y share the same location.
// If we change x, we can see the changes being reflected in y.

union Test {
    int x, y;
};

// Size of a union is taken according the size of largest member in union.
union Ints {
    int x, y;
};

union IntAndChar {
    int x;
    char y;
};

union IntArrAndChar {
    int arr[10];
    char y;
};

// Unions can be useful in many situations where we want to use same memory for
// two ore more members. For example, suppose we want to implement a binary tree
// data structure where each leaf node has a double data value, while each internal
// node has pointers to two children, but no data. If we declare this as:

//  struct NODE {
//      struct NODE *left;
//      struct NODE *right;
//      double data;
//  };

// then every node requires 16 bytes, with half the bytes for each type of node.
// On the other hand, if we declare a node as following, then we can save space:

struct NODE {
    bool is_leaf;
    union {
        struct {
            struct NODE *left;
            struct NODE *right;
        } internal;
        double data;
    } info;
};


int main() {
    // A union variable t
    union Test t;

    t.x = 2; // t.y also gets value 2
    printf("After making x = 2:\n x = %d, y = %d\n\n", t.x, t.y); // outputs 2, 2

    t.y = 10; // t.x also gets updated to 10
    printf("After making y = 10:\n x = %d, y = %d\n\n", t.x, t.y); // outputs 10, 10

    printf("sizeof(Ints) = %lu, sizeof(IntAndChar) = %lu, sizeof(IntArrAndChar) = %lu\n",
           sizeof(union Ints), sizeof(union IntAndChar),
           sizeof(union IntArrAndChar)); // outputs 4, 4, 40

    // Like structures, we can have pointers to unions and can access members using arrow operator (->).
    // The following example demonstrates the same.
    union IntAndChar p1;
    p1.x = 65;

    // p2 is a pointer to union p1
    union IntAndChar *p2 = &p1;

    // Accessing union members using pointer
    printf("%d, %c\n", p2->x, p2->y); // outputs 65, A
}