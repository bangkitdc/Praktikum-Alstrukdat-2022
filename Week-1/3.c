// beasiswa

#include <stdio.h>

int IsValid(int ip, int min, int max) {
	return (ip >= min && ip <= max);
}

int main() {
	float ip, pot;
	int kategori;

	scanf("%f", &ip);
	scanf("%f", &pot);

	if (IsValid(ip, 0, 4)) {
		if (ip >= 3.5) {
			kategori = 4;
		} else if (pot < 1 && ip < 3.5) {
			kategori = 1;
		} else if (pot >= 1 && pot < 5 && ip < 3.5) {
			if (ip >= 2.0) {
				kategori = 3;
			} else {
				kategori = 2;
			}
		} else {
			kategori = 0;
		}
	} 
	printf("%d\n", kategori);

	return 0;
}