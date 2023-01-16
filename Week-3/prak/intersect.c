#include <stdio.h>
#include "liststatik.h"

int main() {
	ListStatik l1, l2, l3;

	readList(&l1);
	readList(&l2);
	CreateListStatik(&l3);

	int i;
	int j = 0;
	for (i = 0; i < listLength(l1); i ++) {
		if (indexOf(l2, ELMT(l1, i)) != IDX_UNDEF) {
			ELMT(l3, j) = ELMT(l1, i);
			j += 1;
		}
	}

	printf("%d\n", listLength(l3));
	sortList(&l3, true);
	printList(l3); printf("\n");

	return 0;
}