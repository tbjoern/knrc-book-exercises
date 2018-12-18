#include <stdio.h>

int main() {
	int space = 0, tab = 0, newline = 0, c;

	while((c = getchar()) != EOF ) {
		switch(c) {
			case ' ': ++space; break;
			case '\t': ++tab; break;
			case '\n': ++newline; break;
		}
	}

	printf("Spaces: %d, Tabs: %d, Newlines: %d\n", space, tab, newline);
}
