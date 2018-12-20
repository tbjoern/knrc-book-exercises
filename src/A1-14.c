#include <stdio.h>

// Task: Create a program that shows a histogram of the length of words in the input

#define CHAR_COUNT 126
#define HISTOGRAM_WIDTH 20
#define HISTOGRAM_SYMBOL '#'
#define COLUMNS 3
#define ROWS (CHAR_COUNT / COLUMNS) + (CHAR_COUNT % COLUMNS)

void print_char_literal(char c) {
	switch(c) {
	case '\b': printf("\\b"); break;
	case '\t': printf("\\t"); break;
	case '\n': printf("\\n"); break;
	case ' ': printf("sp"); break;
	default: if(c > 31) printf("%2c", c); else printf("%2d", c); break;
	}
}

int is_whitespace(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

void add_word(int *hist, int word_length) {
	if(word_length > CHAR_COUNT) {
		++hist[0];
	} else {
		++hist[word_length];
	}
}

int main() {
	int c, wlength;
	int hist[CHAR_COUNT + 1];

	for(int i = 0; i <= CHAR_COUNT; ++i)
		hist[i] = 0;

	wlength = 0;
	// get histogram data
	while((c = getchar()) != EOF) {
		++hist[c];		
	}

	// print histogram
	int max_items;
	max_items = 1;
	for(int length = CHAR_COUNT; length >= 0; --length) {
		if(max_items < hist[length]) {
			max_items = hist[length];
		}
	}
	int bar_width, row_count;
	for(int row = 0; row <= ROWS; ++row) {
		for(int c = row, col = 0; c <= CHAR_COUNT && col < COLUMNS; c += ROWS, ++col) {
			print_char_literal(c);
			printf(" | ");
			bar_width = (hist[c] * HISTOGRAM_WIDTH) / max_items;
			for(int width = 1; width <= bar_width; ++width) {
				putchar(HISTOGRAM_SYMBOL);
			}
			for(int width = bar_width + 1; width <= HISTOGRAM_WIDTH; ++width) {
				putchar(' ');
			}
		}
		putchar('\n');
	}
}

