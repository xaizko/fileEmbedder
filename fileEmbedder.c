/* fileEmbedder.c */
#include "fileEmbedder.h"


int main(int argc, char *argv[]) {
    char *identifier = NULL;
    language lang = c;

    // Check if we don't have enough arguments
    if (argc < 2) {
        usage(argv[0]);
    }
    
    // Check for help flags
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        usage(argv[0]);
    }
    
    if (argc == 2) {
        // Simple case: just the identifier
        identifier = argv[1];
    } else if (argc == 3) {
        // Check for assembly flag
        if (strcmp(argv[1], "-a") == 0) {
            lang = asm;
            identifier = argv[2];
        } else {
            usage(argv[0]);
        }
    } else {
        // Too many arguments
        usage(argv[0]);
    }

    printHeader(identifier, lang);
    printBody(lang);

    return 0;
}

void usage(char *arg) {
    fprintf(stderr, "Usage: %s [-h | --help | -a] <identifier>\n", arg);
    exit(-1);
}

void printHeader(char *identifier, language lang) {
    switch (lang) {
	case asm:
	    printf("%s:\n", identifier);
	    break;
	default:
	    printf("unsigned char %s[] =\n", identifier);
	    break; 
    }
}

void printBody(language lang) {
    int32 n;
    signed int ret;
    char buf[2];
    char *c;

    *buf= *(buf+1) = 0;

    while ( (ret = read(0, $c buf, 1)) == 1 ) {
	n++;
	c = convert(*buf, lang);
	assert(c);
    }
}
