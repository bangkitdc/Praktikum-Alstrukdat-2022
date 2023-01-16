#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "tokenmachine.h"

int main() {
	int op1, op2, res;
	Stack s;
	CreateEmpty(&s);

	startToken();
	if (endToken) {
		printf("Ekspresi kosong\n");
	} else {
		while(!endToken) {
			if (currentToken.tkn == 'b') {
				Push(&s, currentToken.val);
				printf("%d\n", currentToken.val);
			} else {
				Pop(&s, &op2);
				Pop(&s, &op1);
				switch (currentToken.tkn) {
					case '+':
						res = op1 + op2;
						break;
					case '-':
						res = op1 - op2;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op1 / op2;
						break;
					case '^':
						res = pow(op1, op2);
						break;
					default:
						break;
				}
				Push(&s, res);
				printf("%d %c %d\n%d\n", op1, currentToken.tkn, op2, res);
			}
			advToken();
		}
		Pop(&s, &res);
		printf("Hasil=%d\n", res);
	}
	return 0;
}
