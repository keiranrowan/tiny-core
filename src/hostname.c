#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv) {
	if (argc > 1) {
		if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
			printf("hostname [-s] <hostname>\n");
			printf("No arguments prints hostname\n");
		} else if (strcmp(argv[1], "-s") == 0) {
			const char *hostname = argv[2];
			int err = sethostname(hostname, strlen(hostname)); 
			if (err != 0) {
				printf("Error setting hostname\n");
				return 1;
			} else {
				printf("Hostname set.\n");
				return 0;
			}
		}
	} else {
		char hostname[HOST_NAME_MAX + 1];
		int err = gethostname(hostname, HOST_NAME_MAX + 1);
		if (err != 0) {
			printf("Error getting hostname.\n");
			return 1;
		} else {
			printf("%s\n", hostname);
			return 0;
		}
	}
}
