// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055
#include <stdio.h>
#include "queue.h"

float avg(Queue q) {
	int i;
	float res = 0;
	
	for (i = 0; i < length(q); i ++) {
		res += (q).buffer[(i + IDX_HEAD(q)) % CAPACITY];
	}
	res /= length(q);
	return res;
}

int min(Queue q) {
	int i;
	int min = (q).buffer[(IDX_HEAD(q)) % CAPACITY];
	
	for (i = 0; i < length(q); i ++) {
		if ((q).buffer[(i + IDX_HEAD(q)) % CAPACITY] < min) {
			min = (q).buffer[(i + IDX_HEAD(q)) % CAPACITY];
		}
	}
	return min;
}

int max(Queue q) {
	int i;
	int max = (q).buffer[(IDX_HEAD(q)) % CAPACITY];
	
	for (i = 0; i < length(q); i ++) {
		if ((q).buffer[(i + IDX_HEAD(q)) % CAPACITY] > max) {
			max = (q).buffer[(i + IDX_HEAD(q)) % CAPACITY];
		}
	}
	return max;
}

int main() {
	Queue q;
	CreateQueue(&q);
	int op, t, val;
	// int min1, max1;
	
	Queue temp;
	CreateQueue(&temp);
	
	do {
		scanf("%d", &op);
		switch (op) {
			case 1:
				scanf("%d", &t);
				if(isFull(q)) {
					printf("Queue penuh\n");
				} else {
					enqueue(&q, t);
				}
				break;
			case 2:
				if (isEmpty(q)) {
					printf("Queue kosong\n");
				} else {
					dequeue(&q, &val);
					enqueue(&temp, val);
				}
				break;
		}
	} while(op != 0);
	
	printf("%d\n", length(temp));
	
	if (isEmpty(temp)) {
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
	} else {
		// minimal
		printf("%d\n", min(temp));
		// maximal
		printf("%d\n", max(temp));
		// rata
		printf("%.2f\n", avg(temp));
	}
	return 0;
}
