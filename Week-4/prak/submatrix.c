#include <stdio.h>
#include "matrix.h"

int main() {
	int N, M;
	Matrix m1;

	scanf("%d", &N);
	scanf("%d", &M);
	readMatrix(&m1, N, N);

	int i, j, im, jm;
	int res, temp, daerah, tempdaerah;
	
	res = 0;
	daerah = 0;
	tempdaerah = 0;

	for (i = 0; i < N - M + 1; i ++) {
		for (j = 0; j < N - M + 1; j ++) {
			tempdaerah += 1;
			temp = 0;
			for (im = 0; im < M; im ++) {
				for (jm = 0; jm < M; jm ++) {
					if (ELMT(m1, im + i, jm + j) != 0) {
						temp++;
					}
				}
			}
			if (temp > res) {
				res = temp;
				daerah = tempdaerah;
			}
		}
	}
	printf("%d\n", daerah);

	return 0;
}