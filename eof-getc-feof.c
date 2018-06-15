#include <stdio.h>

// In C/C++, getc() returns EOF when end of file is reached.
// getc() also returns EOF when it fails. So, only comparing
// the value returned by getc() with EOF is not sufficient to
// check for actual end of file. To solve this problem, C provides
// feof() which returns non-zero value only if end of file has
// reached, otherwise it returns 0.

void eof_check_with_getc_and_feof(FILE *fp) {
    int ch = getc(fp);
    while (ch != EOF) {
        putchar(ch);
        ch = getc(fp);
    }

    if(feof(fp)) {
        printf("\n End of file reached.");
    } else {
        printf("\n Something went wrong.");
    }

    fclose(fp);

    getchar();
}

int main(void) {
    FILE *fp = fopen("test.txt", "a+");
    fprintf(fp, "EOF, getc() and feof() discussion.");
    eof_check_with_getc_and_feof(fp);
    remove("test.txt");
    return 0;
}