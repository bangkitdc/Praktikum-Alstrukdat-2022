#include <stdio.h>
#include "listlinier.h"

int main () {
	List cache;
	CreateList(&cache);
	
	int n;
	scanf("%d", &n);
	
	int op, i, x;
	int idx, temp;
	float count = 0;
	scanf("%d", &op);
	for (i = 0; i < op; i ++) {
		scanf("%d", &x);
		idx = indexOf(cache, x);
		if (idx == IDX_UNDEF) {
			printf("miss ");
			if (length(cache) < n) { // belum penuh
				insertFirst(&cache, x);
			} else {
				if (n != 0) {
					deleteLast(&cache, &temp);
					insertFirst(&cache, x);
				}
			}
		} else {
			count += 1;
			printf("hit ");
			deleteAt(&cache, idx, &temp);
			insertFirst(&cache, x);
		}
		displayList(cache); printf("\n");
	}
	printf("hit ratio: ");
	if (op == 0) {
		printf("%.2f\n", count);
	} else {
		printf("%.2f\n", count / op);
	}
	
	return 0;
}
