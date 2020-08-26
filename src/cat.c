#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
		printf("cat [FILE]...\n- to read stdin\n");
	} else if (strcmp(argv[1],"-") == 0) {
		char ch;
		while ((ch = getc(stdin)) != EOF) {
			putc(ch, stdout);
		}
	} else {
		int i;
		for (i = 1; i < argc; i++) {
			FILE *fp;
			char ch;
			fp = fopen(argv[i], "r");
			if (fp) {
				while ((ch = getc(fp)) != EOF) {
					putc(ch, stdout);
				}
				fclose(fp);
			}
		}
	}
}
