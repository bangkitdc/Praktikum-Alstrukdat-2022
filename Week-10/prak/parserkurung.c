#include <stdio.h>
#include "stacklinked.h"
#include "charmachine.h"

int main() {
	Stack q1;
	CreateStack(&q1);
	int val;
	boolean valid = true;
	int max = 0;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	
	START();
	while (!EOP) {
		if (currentChar == ']') {
			if (!isEmpty(q1)) {
				pop(&q1, &val);
				if (val != 0) {
					valid = false;
					push(&q1, val);
				} else {
					count0 += 1;
				}
			} else {
				valid = false;
			}
			DisplayStack(q1); printf("\n");
		} else if (currentChar == ')') {
			if (!isEmpty(q1)) {
				pop(&q1, &val);
				if (val != 1) {
					valid = false;
					push(&q1, val);
				} else {
					count1 += 1;
				}
			} else {
				valid = false;
			}
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '|') {
			if (!isEmpty(q1)) {
				pop(&q1, &val);
				if (val != 2) {
					push(&q1, val);
					push(&q1, 2);
				} else {
					count2 += 1;
				}
			} else {
				push(&q1, 2);
			}
			
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '}') {
			if (!isEmpty(q1)) {
				pop(&q1, &val);
				if (val != 3) {
					valid = false;
					push(&q1, val);
				} else {
					count3 += 1;
				}
			} else {
				valid = false;
			}
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '>') {
			if (!isEmpty(q1)) {
				pop(&q1, &val);
				if (val != 4) {
					valid = false;
					push(&q1, val);
				} else {
					count4 += 1;
				}
			} else {
				valid = false;
			}	
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '[') {
			push(&q1, 0);
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '(') {
			push(&q1, 1);
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '{') {
			push(&q1, 3);
			DisplayStack(q1); printf("\n");
		} else if (currentChar == '<') {
			push(&q1, 4);
			DisplayStack(q1); printf("\n");
		} 
		if (max < length(q1)) {
			max = length(q1);
		}
		ADV();
	}
	
	if (!isEmpty(q1)) {
		valid = false;
	}
	
	if (valid) {
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n", count0, count1, count2, count3, count4);
		printf("MAX %d\n", max);
	} else {
		printf("kurung tidak valid\n");
	}
	
	return 0;
}
