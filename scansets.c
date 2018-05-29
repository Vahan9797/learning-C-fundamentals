#include <stdio.h>

int main(void) {
    char str_cap[128], str_occ[128];

    // scanf family functions support scanset specifiers which are represented
    // by %[]. Inside scanset, we can specify single character or range of characters.
    // While processing scanset, scanf will process only those characters which are
    // part of scanset. We can define scanset by putting characters inside square brackets.
    // Please note that the scansets are case-sensitive.

    printf("Enter a string: ");
    // below example stores only capital letters to character array 'str'
    scanf("%[A-Z]s", str_cap);
    printf("You entered %s\n", str_cap);

    printf("Enter a string: ");
    // If first character of scanset is ‘^’, then the specifier will stop reading after first
    // occurence of that character.
    scanf("%[^o]s", str_occ);
    printf("You entered %s\n", str_occ);

    return 0;
}