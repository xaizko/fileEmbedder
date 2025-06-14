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
#include <string.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
typedef unsigned _BitInt(128) int128;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $16 (int128)
#define $c (char *)
#define $i (int)


enum e_language {
    c = 0,
    asm = 1
};
typedef enum e_language language;

int main(int,char**);
void usage(char *arg);
void printHeader(char *identifier, language lang);
void printBody(language lang);
