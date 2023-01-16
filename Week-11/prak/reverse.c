#include <stdio.h>
#include "listrec.h"

List inverseList (List l) {
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
 	// ALGORITMA
 	
 	if (isEmpty(l)) {
 		return NULL;
 	} else {
 		return konsb(inverseList(tail(l)), head(l));
 	}
}

void displayList2(List l, boolean end) {
	// ALGORITMA
    	if (!isEmpty(l)) {
    		if (end && length(l) == 1) {
	    		printf("%d\n", INFO(l));
    		} else {
	    		printf("%d ", INFO(l));
    		}
        	displayList2(NEXT(l), end);
    	}
}

void splitPartisi(List *l1, int k) {
	int counter = 0;
	List ltemp = NULL;

	if (isEmpty(*l1)) {
		return;
	} else {
		while (counter < k) {
			if (!isEmpty(*l1)) {
				ltemp = konsb(ltemp, head(*l1));
				*l1 = tail(*l1);
			}
			counter ++;
		}
		displayList2(inverseList(ltemp), length(*l1) == 0);
		splitPartisi(l1, k);
	}
}

int main() {
	List l;
	l = NULL;
	int panjang, k;
	int i, val, tanda;
	
	scanf("%d %d", &panjang, &k);
	for (i = 1; i <= panjang; i ++) {
		scanf("%d", &val);
		l = konsb(l, val);
	}
	
	if (k != 0) {
		splitPartisi(&l, k);
	} else {
		displayList2(l, true);
	}

	return 0;
}