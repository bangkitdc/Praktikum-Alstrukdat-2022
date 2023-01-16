// diamond

#include <stdio.h>

int IsValid(int n) {
	return (n % 2 == 1);
}

int main() {
	int n;
	int i, j, k;
	scanf("%d", &n);

	if (IsValid(n)) {
		int space = (n - 1) / 2;
		int stars = 1;

		for (i = 0; i < (n + 1) / 2; i++) {
			for (j = 0; j < space; j++) {
				printf(" ");
			}
			for (k = 0; k < stars; k++) {
				printf("*");
			}
			space -= 1;
			stars += 2;
			printf("\n");
		}

		space = 1;
		stars = (n - 2);
		for (i = 0; i < (n - 1) / 2; i++) {
			for (j = 0; j < space; j++) {
				printf(" ");
			}
			for (k = 0; k < stars; k++) {
				printf("*");
			}
			space += 1;
			stars -= 2;
			printf("\n");
		}
	} else {
		printf("Masukan tidak valid\n");
	}

	return 0;
}