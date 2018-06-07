#include <stdio.h>

// Enumeration (or enum) is a user defined data type in C.
// It is mainly used to assign names to integral constants,
// the names make a program easy to read and maintain.

// The keyword ‘enum’ is used to declare new enumeration types in C and C++.
// Followings are examples of enum declaration.

// Also, two enum names can have same value.
// If we don't assign any value, compiler automatically assigns values starting from 0.
enum State {Working = 1, Failed = 0, Freezed = 0};

// here constant1 = 0, constant2 = 1, constant3 = 2
enum flag {constant1, constant2, constant3};

// enums can also be defined this way:
enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun} day;

enum year{Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

// We can assign values to some name in any order.
// All unassigned names get value as value of previous name plus one.
enum days{sunday = 1, monday, tuesday = 5, wednesday, thursday = 10, friday, saturday};

// All enums must be unique in their scope.
// For example, example below fails in compilation,
// because 'Failed' was already declared in State enum.
// enum Result {Failed, Passed}; // <-- uncomment this line to see fail in action

int main() {
    // they can also be declared like this:
    enum week day1;
    day1 = Wed;
    printf("%d\n", day1); // outputs 2

    for(int i = Jan; i <= Dec; i++) {
        printf("%d ", i); // outputs (0...11) range
    }

    printf("\n%d %d %d %d %d %d %d\n", sunday, monday, tuesday, wednesday, thursday, friday, saturday); // outputs 1 2 5 6 10 11 12
    return 0;
}

//  Enum vs Macro
//  We can also use macros to define names constants. For example we can define ‘Working’ and ‘Failed’ using following macro.
//
//  #define Working 0
//  #define Failed 1
//  #define Freezed 2
//  There are multiple advantages of using enum over macro when many related named constants have integral values.
//      a) Enums follow scope rules.
//      b) Enum variables are automatically assigned values.