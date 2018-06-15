#include <stdio.h>
#include <stdlib.h>

// In C, fopen() is used to open a file in different modes.
// To open a file in write mode, “w” is specified. When mode
// “w” is specified, it creates an empty file for output operations.

/** @What @if @the @file @already @exists?
    If a file with the same name already exists, its contents are discarded
    and the file is treated as a new empty file. For example, in the following
    program, if “test.txt” already exists, its contents are removed and
    “GeeksforGeeks” is written to it.*/

void open_and_rewrite_file(FILE *fp) {
    if(fp == NULL) {
        puts("Couldn't open file");
        exit(0);
    } else {
        fputs("GeeksForGeeks", fp);
        puts("Done");
        fclose(fp);
    }
}

// The latest C standard C11 provides a new mode “x” which is exclusive
// create-and-open mode. Mode “x” can be used with any “w” specifier,
// like “wx”, “wbx”. When x is used with w, fopen() returns NULL if
// file already exists or could not open. Following is modified C11
// program that doesn’t overwrite an existing file.

void open_and_write_if_does_not_exist(FILE *fp) {
    FILE *fp = fopen("test.txt", "wx");
    if(fp == NULL) {
        puts("Couldn't open file or file already exists");
        exit(0);
    } else {
        fputs("GeeksforGeeks", fp);
        puts("Done");
        fclose(fp);
    }
}

int main(void) {
    FILE *fp = fopen("test.txt", "w");
    open_and_rewrite_file(fp);
    open_and_write_if_does_not_exist(fp);
    return 0;
}