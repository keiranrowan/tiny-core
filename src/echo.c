#include <stdio.h>

int main(int argc, char** argv) {
    if (argc > 1) {
        int i;
        for (i = 1;i < argc;i++) {
            printf("%s ",argv[i]);
        }
        printf("\n");
    } else {
        printf("\n");
    }
}
