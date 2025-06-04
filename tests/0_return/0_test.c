#include <stdio.h>

extern int entry();

/** Driver for Entry */
void main() {
	FILE *f = fopen("tests/0_return/0_basic.out", "w");
	int retval = entry();
	fprintf(f, "%d", retval);
}
