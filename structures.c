#include <stdio.h>

// Structure is a user defined data type in C/C++.
// A structure creates a data type that can type that
// can be used to group items of possibly different types into a single type.

// 'struct' keyword is used to create a structure. Following is an example.
struct Address {
    char name[50];
    char street[100];
    char city[50];
    char state[20];
    int pin;
} addr1; // <-- this is an example of a way of declaring structure variable

// You can't initialize Struct members with declaration.
// The reason is simple, when a data type is declared, no
// memory is allocated for it. Memory is allocated only
// when variables are created.
struct Point {
    int x /*= 0*/; // Assigning default value for variables in declaration will cause compile error
    int y /*= 0*/; // <-- Uncomment this 2 lines to see the 'COMPILER ERROR: cannot initialize members here'
    int z;
};

int main(void) {
    // in C++ 'struct' keyword is optional before
    // in declaration of variable. In C, it is mandatory.
    struct Address addr2; // <-- this is also a way of declaring structure variable

    // Structure members, however, can be initialized using curly braces '{}'.
    // For example, the following is a valid initialization.
    struct Point p1 = {0, 1};

    // Structure members are accessed using dot (.) operator.
    p1.x = 20;
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y); // <-- outputs 20 1

    // Designated initialization allows structure members to be initialized
    // in any order. This feature has been added in C99 standard. This feature
    // is not available in C++ and works only in C. For example:
    struct Point p2 = {.y = 0, .z = 1, .x = 2};
    struct Point p3 = {.x = 70};

    printf("p2.x = %d, p2.y = %d, p2.z = %d\n", p2.x, p2.y, p2.z); // <-- outputs 2 0 1
    printf("p3.x = %d\n", p3.x); // <-- outputs 70

    // Like other primitive data types, we can create an array of structures.
    struct Point point_arr[10];

    // Accessing array members
    point_arr[0].x = 10;
    point_arr[0].y = 20;

    printf("point_arr[0].x = %d, point_arr[0].y %d\n", point_arr[0].x, point_arr[0].y); // <-- outputs 10 20

    // Like primitive types, we can have pointer to a structure.
    // If we have a pointer to structure, members are accessed
    // using arrow (->) operator.

    // ptr is a pointer structure to point_arr[0]
    struct Point *ptr = &point_arr[0];

    // Accessing structure members using structure pointer
    printf("ptr->x = %d, ptr->y = %d\n", ptr->x, ptr->y); // outputs 10 20

    return 0;
}