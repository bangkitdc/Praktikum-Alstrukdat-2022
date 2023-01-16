// ip mahasiswa

#include <stdio.h>

int IsWithinRange(float ip, int min, int max) {
	return (ip >= min && ip <= max);
}

int main() {
	float ip, jumlah;
	int lulus, mhs;
	jumlah = 0;
	mhs = 0;
	lulus = 0;

	scanf("%f", &ip);
	while(ip != -999) {
		if (IsWithinRange(ip, 0, 4)) {
			mhs += 1;
			jumlah += ip;
			if (ip >= 2.75) {
				lulus += 1;
			}
		}

		scanf("%f", &ip);
	}

	if (mhs == 0) {
		printf("Tidak ada data\n");
	} else {
		int tdklulus;
		float rata;

		rata = jumlah / mhs;
		tdklulus = mhs - lulus;

		printf("%d\n", mhs);
		printf("%d\n", lulus);
		printf("%d\n", tdklulus);
		printf("%.2f\n", rata);
	}
	return 0;
}