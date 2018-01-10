#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char tst[100] = "ls | grep hello";

	printf("tst: %s addr:%p\n", tst, tst + 3);
	printf("'|' addr: %p\n", strpbrk(tst, "|"));
	return 0;
}
