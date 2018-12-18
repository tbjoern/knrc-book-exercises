#include <stdio.h>

int main() {
        int c;

	while((c = getchar()) != EOF) {
		putchar(c);
		if(c == ' ') {
			while((c = getchar()) != EOF && c == ' ')
				;
			if(c != EOF) {
				putchar(c);
			}
		}
	}
}
