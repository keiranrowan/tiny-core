#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc > 1 && argc < 3) {
        if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
            printf("yes [STRING]...\nPrints y or given string repeatedly\n");
        } else {
            for(;;) {
                printf("%s\n", argv[1]);
            }
        }
    } else {
        for(;;) {
            printf("y\n");
        }
    }
}
