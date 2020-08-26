#include <stdio.h>
#include <string.h>
#include <ctype.h>

void help();

int main(int argc, char **argv) {
	if (argc > 2) {
		if (strcmp(argv[1], "-h") == 0) {
			help();
		} else if (strcmp(argv[1], "-l") == 0) {
			if (strcmp(argv[2], "-") == 0) { 
			    int n;
				char ch;

				while ((ch = getc(stdin)) != EOF) {
					if (ch == '\n') {
						n++;
					}
				}

				printf("%i\n", n);
			} else {
				int i, n = 0;
				for (i = 2; i < argc; i++) {
					FILE *fp;
					char ch;
					
					fp = fopen(argv[i], "r");
					if (fp) {
						while ((ch = getc(fp)) != EOF) {
							if (ch == '\n') {
								n++;
							}
						}
						fclose(fp);
					}
				}
				
				printf("%i\n", n);
			}
		} else if (strcmp(argv[1], "-b") == 0) {
			if (strcmp(argv[2], "-") == 0) {
				int n = 0;
				char ch;

				while ((ch = getc(stdin)) != EOF) {
					n++;
				}

				printf("%i\n", n);
			} else {
				int i, n = 0;
				for (i = 2; i < argc; i++) {
					FILE *fp;
					char ch;
					
					fp = fopen(argv[i], "r");
					if (fp) {
						while ((ch = getc(fp)) != EOF) {
							n++;
						}
						fclose(fp);
					}
				}
				
				printf("%i\n", n);
			}
		} else if (strcmp(argv[1], "-w") == 0) {
			if (strcmp(argv[2], "-") == 0) {
				int n = 0, alpha = 0;
				char ch;

				while ((ch = getc(stdin)) != EOF) {
					if (!isspace(ch)) {
						alpha = 1;
					} else {
						if (alpha) {
							alpha = 0;
							n++;
						}
					}
				}

				printf("%i\n", n);
			} else {
				int i, n = 0;
				for (i = 2; i < argc; i++) {
					FILE *fp;
					char ch;
					
					fp = fopen(argv[i], "r");
					if (fp) {
						int alpha = 0;
						
						while ((ch = getc(fp)) != EOF) {
							if (!isspace(ch)) {
								alpha = 1;
							} else {
								if (alpha) {
									alpha = 0;
									n++;
								}
							}
						}
						fclose(fp);
					}
				}
				
				printf("%i\n", n);
			}
		} else if (strcmp(argv[1], "-c") == 0) {
			if (strcmp(argv[2], "-") == 0) {
				int n = 0;
				char ch;
				
				while ((ch = getc(stdin)) != EOF) {
					if (!(ch == '\n') || !(ch == '\t') || !(ch == ' ')) {
						n++;
					}
				}
				
				printf("%i\n", n);
			} else {
				int i, n = 0;
				for (i = 2; i < argc; i++) {
					FILE *fp;
					char ch;
					
					fp = fopen(argv[i], "r");
					if (fp) {
						while ((ch = getc(fp)) != EOF) {
							if (!(ch == '\n') || !(ch == '\t') || !(ch == ' ')) {
								n++;
							}
						}
						fclose(fp);
					}
				}
				
				printf("%i\n", n);
			}
		} else {
			printf("Missing flags...\n");
			help();
		}
	} else {
		printf("Invalid arguments...\n");
		help();
	}
}

void help() {
	printf("wc [-w|-c|-l] [FILE]...\n");
	printf("    -w = Print word count\n");
	printf("    -c = Print character count\n");
	printf("    -l = Print line count\n");
}
