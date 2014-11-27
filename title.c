#include <stdio.h>
#include <unistd.h>

int main() {

		printf("\e(0%c\e(B", 0x6c);

	return 0;
}
