#include<stdio.h>
#include <stdlib.h>
#include "file_utils.h"
int main(int argc, char *argv[]) {
    if (argc != 3) {
       fprintf(stderr, "usage: %s INPUT_FILENAME OUTPUT_FILENAME\n", argv[0]);
    } else {
        char *buffer;
        int size = read_file(argv[1], &buffer);
        if(size != -1) {
            write_file(argv[2], buffer, size);
        } else {
            fprintf(stderr, "An error occurred while reading the file.\n");
        }
        free(buffer);
    }
    return 0;
}
