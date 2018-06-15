#include <stdio.h>
#include <stdlib.h>
// In C, fseek() should be preferred over rewind()

// Note the following text C99 standard:
// - The rewind function sets the file position indicator for
// the stream pointed to by stream to the beginning of the file.
// It is equivalent to "(void)fseek(stream, 0L, SEEK_SET)", except
// that the error indicator for the stream is also cleared.

// This following code example sets the file position indicator of
// an input stream back to the beginning using rewind(). But there
// is no way to check whether the rewind() was successful.

void manage_file_with_rewind(FILE *fp) {
    if(fp == NULL) {
        // Handle open error
    }

    rewind(fp); // no way to check if rewind is successful

    // Do more precessing with file...

    fclose(fp);
}

// In the code above, fseek() can be used instead of rewind()
// to see if the operation succeeded. Following lines of code
// can be used in place of rewind(fp);

void manage_file_with_fseek(FILE *fp) {
    if(fp == NULL) {
        // Handle open error
    }

    if(fseek(fp, 0L, SEEK_SET) != 0) { // fseek() returns the position indicator value
        // Handle repositioning error
    }
    // Do more precessing with file...

    fclose(fp);
}

int main(void) {
    FILE *fp = fopen("test.txt", "a+");
    fprintf(fp, "FSEEK() VS REWIND()");
    manage_file_with_rewind(fp);
    manage_file_with_fseek(fp);
    remove("test.txt");
}