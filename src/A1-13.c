#include <stdio.h>

// Task: Create a program that shows a histogram of the length of words in the input

#define MAX_WORD_LENGTH 10
#define HISTOGRAM_WIDTH 20
#define HISTOGRAM_SYMBOL '#'

int is_whitespace(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

void add_word(int *hist, int word_length) {
	if(word_length > MAX_WORD_LENGTH) {
		++hist[0];
	} else {
		++hist[word_length];
	}
}

int main() {
	int c, wlength;
	int hist[MAX_WORD_LENGTH + 1];

	for(int i = 0; i <= MAX_WORD_LENGTH; ++i)
		hist[i] = 0;

	wlength = 0;
	// get histogram data
	while((c = getchar()) != EOF) {
		if(is_whitespace(c)) {
			if(wlength != 0) {
				add_word(hist, wlength);
				wlength = 0;
			}
		} else {
			++wlength;
		}
	}

	// print histogram
	int max_items;
	max_items = 1;
	for(int length = MAX_WORD_LENGTH; length >= 0; --length) {
		if(max_items < hist[length]) {
			max_items = hist[length];
		}
	}
	int bar_width;
	for(int length = 0; length <= MAX_WORD_LENGTH; ++length) {
		printf("%2d: ",length);
		bar_width = (hist[length] * HISTOGRAM_WIDTH) / max_items;
		for(int width = 1; width <= bar_width; ++width) {
			putchar(HISTOGRAM_SYMBOL);
		}
		putchar('\n');
	}
}

