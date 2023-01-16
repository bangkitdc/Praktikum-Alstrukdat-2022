#include <stdio.h>
#include "wordmachine.h"

int main() {
	int length = 0;
	
	STARTWORD();
	while(!endWord) {
		if (currentWord.Length > length) {
			length = currentWord.Length;
		}
		ADVWORD();
	}
	printf("%d\n", length);
	
	return 0;
}
