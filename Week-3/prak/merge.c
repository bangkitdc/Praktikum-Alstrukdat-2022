#include <stdio.h>
#include "listdin.h"

int main() {
	ListDin l1, l2, l3;

	CreateListDin(&l1, 200);
	readList(&l1);
	CreateListDin(&l2, 200);
	readList(&l2);

	copyList(l1, &l3);
	int i;
	for (i = 0; i < listLength(l2); i ++) {
		if (indexOf(l1, ELMT(l2, i)) == IDX_UNDEF) {
			insertLast(&l3, ELMT(l2, i));
		}
	}
	sort(&l3, true);
	printf("%d\n", listLength(l3));
	printList(l3); printf("\n");

	return 0;
}