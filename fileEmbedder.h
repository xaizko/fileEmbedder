/* fileEmbedder.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

enum e_language {
    c = 0,
    assembly = 1
};
typedef enum e_language language;

int main(int,char**);
void usage(char *arg);
void printHeader(char *identifier, language lang);
void printBody(language lang);
char *convert(char ch, language lang);

