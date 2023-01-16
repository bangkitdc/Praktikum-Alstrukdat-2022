// Nama: Muhammad Bangkit Dwi C.
// NIM: 13521055

#include <stdio.h>
#include "time.h"

int main() {
	int N, i;
	TIME t1, t2, taw, takh, temp;
	scanf("%d", &N);
	for (i = 0; i < N; i ++) {
		printf("[%d]\n", i + 1);
		BacaTIME(&t1);
		BacaTIME(&t2);
		if (TGT(t1, t2)) {
			temp = t1;
			t1 = t2;
			t2 = temp;
		}
		printf("%d\n", Durasi(t1, t2));
		if (i == 0) {
			taw = t1;
			takh = t2;
		} else {
			if (TLT(t1, taw)) {
				taw = t1;
			}
			if (TGT(t2, takh)) {
				takh = t2;
			}
		}
	}
	TulisTIME(taw); printf("\n");
	TulisTIME(takh); printf("\n");
	return 0;
}