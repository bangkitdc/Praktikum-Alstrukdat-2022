#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.h"
#include "charmachine.h"

int main() {
	Queue q1 ,q2, q3;
	ElType val, val2, val3;
	boolean flag;
	int i, len;

	CreateQueue(&q1);
	CreateQueue(&q2);
	CreateQueue(&q3);

	len = 0;
	flag = false;
	START();
	while (!EOP) {
		if (flag) {
			if (currentChar == 'B') {
				enqueue(&q2, 0);
			} else if (currentChar == 'K') {
				enqueue(&q2, 1);
			}
			len += 1;
		} else {
			if (currentChar == ',') {
				flag = true;
			} else {
				if (currentChar == 'B') {
					enqueue(&q1, 0);
				} else if (currentChar == 'K') {
					enqueue(&q1, 1);
				}
			}
		}
		ADV();
	}

	for (i = 0; i < len; i ++) {
		enqueue(&q3, i + 1);
	}

	i = 0;
	while (i < length(q3) && !isEmpty(q2)) {
		if (HEAD(q1) == HEAD(q2)) {
			dequeue(&q1, &val);
			dequeue(&q2, &val2);
			dequeue(&q3, &val3);
			if (val2 == 0) {
				printf("%d -> bulat\n", val3);
			} else if (val2 == 1) {
				printf("%d -> kotak\n", val3);
			}
			i = 0;
		} else {
			dequeue(&q3, &val3);
			enqueue(&q3, val3);
			dequeue(&q1, &val);
			enqueue(&q1, val);
			i ++;
		}
	}
	printf("%d\n", length(q1));
}
