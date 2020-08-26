#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
	char hostname[HOST_NAME_MAX + 1];
	gethostname(hostname, HOST_NAME_MAX + 1);
	printf("%s\n", hostname);
	return 0;
}
