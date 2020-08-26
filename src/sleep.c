#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc > 1) {
#ifdef _WIN32
		Sleep(atoi(argv[1]));
#else
		sleep(atoi(argv[1]));
#endif
	}
}
