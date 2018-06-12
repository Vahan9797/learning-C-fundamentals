#include <stdio.h>

// In C, we can specify size (in bits) of structure and union members.
// The idea to use memory efficiently when we know that the value of a field
// or group of fields will never exceed a limit or is within a small range.

// For example, consider the following declaration of date without use of bit fields.
struct date_without_bits {
    unsigned int d;
    unsigned int m;
    unsigned int y;
};

// Knowing, that day can have maximum 31 value and month can have maximum 12 value,
// we can optimize the space using bit fields.
struct date_with_bits {
    unsigned int d: 5;
    unsigned int m: 4;
    unsigned int y;
};

/*** @Some @interesting @facts @about @bit @fields: **/
// 1. A special unnamed bit field of size 0 is used to force alignment on next boundary.
//    For example consider the following program.

struct test_without_zero_field {
    unsigned int x: 5;
    unsigned int y: 8;
};

struct test_with_zero_field {
    unsigned int x: 5;
    unsigned int: 0;
    unsigned int y: 8;
};

// 2. We cannot have pointers to bit field members as they may not start a byte boundary.

struct test_pointer_to_bit_field {
    unsigned int x: 5;
    unsigned int y: 5;
    unsigned int z;
};

// 3. It is implementation defined to assign an out-of-range value to a bit field member.

struct test_out_of_range_value {
    unsigned int x: 2;
    unsigned int y: 2;
    unsigned int z: 2;
};

// 4. In C++, we can have static members in a structure/class, but bit fields cannot be static.

/** @The @lines @below @are @commented @to @pass @the @compilation */
//  struct test_static_member {
//      static unsigned int x; // this compiles and works in C++, but not in C.
//  };

//  struct test_static_bit_field {
//      static unsigned int x: 5; // this neither works in C++, nor in C.
//  };

// 5. Array of bit fields is not allowed. For example, the below program fails in compilation.
struct test_bit_field_array {
    //unsigned int x[10]: 5; // <-- Uncomment this line to see the bit-field invalid type error
};

int main() {
    printf("Size of date_without_bits is %ld bytes\n", sizeof(struct date_without_bits)); // outputs 12
    struct date_without_bits dt = {31, 12, 2014};
    printf("Date is %d/%d/%d\n", dt.d, dt.m, dt.y); // outputs 31/12/2014

    printf("Size of date_with_bits is %ld bytes\n", sizeof(struct date_with_bits)); // outputs 8
    struct date_with_bits dtb = {31, 12, 2015};
    printf("Date is %d/%d/%d\n", dtb.y, dtb.m, dtb.y); // outputs 31/12/2015

    printf("Size of test_without_zero_field is %ld bytes\n", sizeof(struct test_without_zero_field)); // outputs 4
    printf("Size of test_with_zero_field is %ld bytes\n", sizeof(struct test_with_zero_field)); // outputs 8

    struct test_pointer_to_bit_field t_pointer;
    //printf("Address of t_pointer.x is %p", &t_pointer.x); // <-- Uncomment this line to see compile error
    printf("Address of t_pointer.z is %p\n", &t_pointer.z); // This line works fine because z is not a bit field member

    struct test_out_of_range_value t_range = {.x = 5};
    printf("Out of range value of t_range.x is %d\n", t_range.x); // output is implementation dependent
}