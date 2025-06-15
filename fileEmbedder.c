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
            lang = assembly;
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

// Prints correct usage if bad one is provided
void usage(char *arg) {
    fprintf(stderr, "Usage: %s [-h | --help | -a] <identifier>\n", arg);
    exit(-1);
}

// Prints file header
void printHeader(char *identifier, language lang) {
    switch (lang) {
    case assembly:
        // Print the identifier as a label first
        printf(".section .data\n");
        printf("%s:\n\t", identifier);
        break;
    case c:
        // For C, print the array declaration first
        printf("unsigned char %s[] = {\n\t", identifier);
        break;
    default:
        printf("unsigned char %s[] = {\n\t", identifier);
        break; 
    }
}

// Prints the actual file data
void printBody(language lang) {
    int32 n = 0;  
    signed int ret;
    char buf[2];
    char *ch;
    bool isFirst = true;  // Track if this is the first byte
    bool hasData = false; // Track if we've read any data

    buf[0] = buf[1] = (char)0;  

    while ((ret = read(0, buf, 1)) == 1) {
        hasData = true;
        
        if (!isFirst) {
            if (n % 16 == 0) {
                if (lang == c) {
                    printf(",\n\t"); 
                } else if (lang == assembly) {
                    printf("\n\t");
                    isFirst = true;  // Reset first item flag after newline
                }
            } else {
                printf(", ");
            }
        }
        
        ch = convert(buf[0], lang);
        assert(ch);        
        printf("%s", ch);  
        
        isFirst = false;
        n++;
        buf[0] = buf[1] = (char)0;
    }

    // Only add closing syntax if we've read some data
    if (hasData) {
        switch(lang) {
        case c:
            printf("\n};\n");  
            break;
        case assembly:
            printf("\n");
            break;
        default:
            printf("\n");
        }
    }
}

// Converts a character to its hex representation based on language
char *convert(char ch, language lang) {
    static char ret[8];  
    memset(ret, 0, 8); 
    
    switch (lang) {
    case assembly:
        snprintf(ret, 7, "0x%.02hhx", ch);
        break;
    default:
    case c:
        snprintf(ret, 7, "0x%.02hhx", ch); 
        break;
    }

    return ret;
}
