
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;
	scanf("%d", &i);

	if (i == 1) {
		printf("This\nIsNot\nMy");
		sleep(6);
	}
}
