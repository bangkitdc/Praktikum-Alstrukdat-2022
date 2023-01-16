#include <stdio.h>
#include "liststatik.h"

void inverse(ListStatik *l) {
	int i;
	ElType temp;

	for (i = 0; i < (listLength(*l) / 2); i ++) {
		temp = ELMT(*l, i);
		ELMT(*l, i) = ELMT(*l, listLength(*l) - i - 1);
		ELMT(*l, listLength(*l) - i - 1) = temp;
	}
}

boolean isMedian(ListStatik *l, ElType x) {

	sortList(l, true);
	if (listLength(*l) % 2 == 0) {
		return (ELMT(*l, -1 + (listLength(*l) / 2)) == x);
	} else {
		return (ELMT(*l, (listLength(*l) / 2)) == x);
	}

}

int main() {
	ListStatik T;
	int x, idx;

	readList(&T);
	printList(T); printf("\n");

	scanf("%d", &x);

	inverse(&T);
	int j, ctr;
	ctr = 0;
	for (j = 0; j < listLength(T); j ++) {
		if (ELMT(T, j) == x) {
			ctr += 1;
		}
	}
	printf("%d\n", ctr);

	idx = indexOf(T, x);
	if (idx == IDX_UNDEF) {
		printf("%d tidak ada\n", x);
	} else {
		printf("%d\n", listLength(T) - idx - 1);

		int max, min;
		extremeValues(T, &max, &min);

		if (x == max) {
			printf("maksimum\n");
		}
		if (x == min) {
			printf("minimum\n");
		}
		if (isMedian(&T, x)) {
			printf("median\n");
		}
	}

	return 0;
}