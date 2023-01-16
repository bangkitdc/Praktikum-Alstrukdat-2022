#include <stdio.h>
#include "prioqueuetime.h"

int main() {
	int N, i;

	PrioQueueTime q;
	infotype X, current;

	scanf("%d", &N);
	MakeEmpty(&q, N);

	// time waktu mulai melayani baru / waktu selesai melayani (yang sebelumnya)
	int target = 0; 

	for (i = 0; i < N; i ++) {
		scanf("%d %c", &Time(X), &Info(X));
		Enqueue(&q, X);
		// kalau sama kayak target, dequeue terus print
		if (i == target) {
			Dequeue(&q, &current);
			printf(
				"%d %c\n",
				i, 
				Info(current)
			);
			target += Time(current);
		}
	}
	// target = mulai detik awal pada sisa queue
	// handle sisa queue

	while (!IsEmpty(q)) {
		Dequeue(&q, &current);
		printf(
			"%d %c\n",
			target, 
			Info(current)
		);
		target += Time(current);
	}

	DeAlokasi(&q);
	return 0;
}

// 6
// 2 o
// 2 n
// 1 c
// 4 i
// 2 d
// 3 g

// 4
// 2 o
// 2 n
// 1 c
// 4 i