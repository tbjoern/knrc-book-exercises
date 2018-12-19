#include <stdio.h>

// Task: Create a program that shows a histogram of the length of words in the input
// Vertical Version

#define MAX_WORD_LENGTH 10
#define HISTOGRAM_HEIGHT 10
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
	// caculate bar heights
	int bar_height[MAX_WORD_LENGTH];
	for(int length = 0; length <= MAX_WORD_LENGTH; ++length) {
		bar_height[length] = (hist[length] * HISTOGRAM_HEIGHT) / max_items;
	}
	// print bars
	for(int level = HISTOGRAM_HEIGHT; level >= 0; --level) {
		for(int word_length = 0; word_length <= MAX_WORD_LENGTH; ++word_length) {
			if(bar_height[word_length] >= level) {
				putchar('#');
			} else {
				putchar(' ');
			}
			putchar(' ');
		}
		putchar('\n');
	}
	// print seperator
	for(int i = 0; i <= MAX_WORD_LENGTH; ++i) {
		putchar('-');
		putchar('-');
	}
	putchar('\n');
	// print x axis
	for(int word_length = 0; word_length <= MAX_WORD_LENGTH; ++word_length) {
		printf("%-2d", word_length);
	}
	putchar('\n');
}
