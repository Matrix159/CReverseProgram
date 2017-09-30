#include <stdio.h>
#include <malloc.h>
#include "file_utils.h"

int read_file(char *fileName, char **buffer) {

    FILE *fp = fopen(fileName, "r");
    int size = 0;
    if (fp == NULL) {
        fprintf(stderr, "File not initialized\n");
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) == 0) {
        size = ftell(fp);
        rewind(fp);
        *buffer = malloc(sizeof(char) * (size));
        fread(*buffer, sizeof(char), size, fp);
        //printf("%s\n", *buffer);
    } else {
	fprintf(stderr, "Error seeking to end of file in read_file\n");
        return -1;
    }
    fclose(fp);
    return size;
}

int write_file(char *fileName, char *buffer, int size) {

    FILE *fp = fopen(fileName, "w");
    fseek(fp, 0, SEEK_SET);
    for(int i = size - 1; i >= 0; i--) {
        //printf("%c", buffer[i]);
        fputc(buffer[i], fp);
    }
    fclose(fp);
    return 0;
}
