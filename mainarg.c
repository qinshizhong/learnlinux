#include <stdio.h>

int main(int argc, char **argv) {
    if (argc > 0) {
        printf("argc = %d.\n", argc);
        for (int i = 0; i < argc; ++i) {
            printf("%s\n", argv[i]);
        }
    }
    else {
        printf("nothing input.\n");
    }
    
    return 0;
}
