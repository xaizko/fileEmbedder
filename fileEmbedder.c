/* fileEmbedder.c */
#include "fileEmbedder.h"

void usage(char *arg) {
    fprintf(stderr, "Usage: %s [-h | --help | -a] <identifier>\n", arg);
    exit(-1);
}

int main(int argc, char *argv[]) {
    bool asm = false;
    char *identifier = NULL;

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
            asm = true;
            identifier = argv[2];
        } else {
            usage(argv[0]);
        }
    } else {
        // Too many arguments
        usage(argv[0]);
    }

    printf("asm = \t%s\n"
           "identifier = '%s'\n",
           (asm) ? "true" : "false",
           identifier);

    return 0;
}