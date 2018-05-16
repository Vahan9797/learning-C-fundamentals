#include <stdio.h>

#define PRINT(x) (#x) // # directive converts its argument in a string, some C magic.
#define INFO 1
#define ERR 2
#define STD_OUT stdout
#define STD_ERR stderr

// To support variable length arguments in macro, we must include ellipses (…) in macro definition.
// There is also “__VA_ARGS__” preprocessing identifier which takes care of variable length argument
// substitutions which are provided to macro.
// Concatenation operator ## (aka paste operator) is used to concatenate variable arguments.

// Also, in multi-line macros every line must end with "\" symbol
// And to provide curly braces as beginning and ending to our macro,
// we must use do while (0) enclosing technique

#define LOG_MESSAGE(prio, stream, msg, ...) do {\
    char *str;\
    if(prio == INFO) str = "INFO";\
    else if(prio == ERR) str = "ERR";\
    fprintf(stream, "[%s] : %s : %d : "msg" \n", str, __FILE__, __LINE__, ##__VA_ARGS__);\
} while (0)

// num & 1 is a bit-wise operation, which compares last bit of numbers binary version with 1, e.g. 9 = (101), 101 & 001 = 001, 12 = (1100), 1100 & 0001 = 0000
#define CHECK_EVEN_ODD_NUMBER(num) do {\
    if(num & 1) \
        printf("%d is Odd number.\n", num);\
    else \
        printf("%d is Even number.\n", num);\
} while (0)

int main(void) {
    char *s = "Hello";

    //printf("%s", PRINT(x));
    // Display normal message
    LOG_MESSAGE(ERR, STD_ERR, "Failed to open file");
    // Provide string as argument
    LOG_MESSAGE(INFO, STD_OUT, "%s Geeks for Geeks", s);
    // Provide integer as arguments
    LOG_MESSAGE(INFO, STD_OUT, "%d + %d = %d", 10, 20, (10 + 20));

    CHECK_EVEN_ODD_NUMBER(9);
    CHECK_EVEN_ODD_NUMBER(12);
    return 0;
}