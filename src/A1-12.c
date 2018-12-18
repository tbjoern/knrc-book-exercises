#include <stdio.h>

#define bool int
#define false 0
#define true 1

int main() {
	int c;
	bool putnewline = false;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			putnewline = true;
		} else {
			if(putnewline) {
				putchar('\n');
				putnewline = false;
			}
			putchar(c);
		}
	}
	putchar('\n');
}
