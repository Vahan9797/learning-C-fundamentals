// In this file there are some complicated declarations for C,
// which are very hard to read at first, but not that hard once you are used to
// parsing it into postfix view and reading it from left to right

// Here are some examples:
int main(void) {
    int (*day_tab)[13];
    // Postfix: day_tab * [13] int
    // Meaning: day_tab is pointer to array of 13 integers

    void (*f[10]) (int, int);
    // Postfix: f[10] * (int, int) void
    // Meaning: f is an array of 10 pointer to function (which takes 2 arguments of type int) returning void

    char (*(*x())[]) ();
    // Postfix: x() * [] * () char
    // Meaning: x is a function returning pointer to array of pointers to function returning char

    char (*(*y[3])())[5];
    // Postfix: y[3] * () * [5] char
    // Meaning: y is an array of 3 pointers to function returning pointer to array of 5 chars

    int *(*(*arr[5])()) ();
    // Postfix: arr[5] * () * () * int
    // Meaning: arr is an array of 5 pointers to functions returning pointer to function returning pointer to integer

    void (*bsd_signal(int sig, void(*func)(int))) (int);
    // Postfix: bsd_signal(int sig, void(*func)(int)) * (int) void
    // Meaning: bsd_signal is a function that takes integer and a pointer to a
    // function(that takes integer as argument and returns void) and returns pointer
    // to a function(that take integer as argument and returns void)

    return 0;
}