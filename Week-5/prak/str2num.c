#include <stdio.h>
#include "wordmachine.h"

boolean isEq(char s1[], char s2[], int length) {
	int i;
	
	for (i = 0; i < length; i ++) {
		if (s1[i] != s2[i]) {
			return false;
		}
	} 
	return true;
}

int main() {
	char *s[16] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", 
	"sebelas", "seratus", "belas", "puluh", "ratus", "nol"};
	
	int d[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 100};

	int i, j;
	
	STARTWORD();
	int val = 0; // naruh integer kalau yang kebaca angka
	int temp2 = 0; // naruh integer yang sebelumnya dibaca (dipakai pas ada kata puluh)
	boolean flag = false; // masih angka
	
	while(!endWord) {
		boolean found = false; // ketemu angka / belas / puluh / ratus

		char temp[currentWord.Length]; // naruh currentWord
		for (i = 0; i < currentWord.Length; i ++) {
			temp[i] = currentWord.TabWord[i];
		}
		j = 0;
		while (j < 16 && !found) { // kalau angka / belas / puluh / ratus
			if (isEq(temp, s[j], currentWord.Length)) {
				found = true;
				if (j <= 11) { // 1 - 100
					val += d[j]; // karena gamungkin angka terus angka (ada pemisah ratus, puluh, belas)
				} else if (j == 15){
					printf("%d ", 0); // 0 jangan lup ges:)
				}else {
					if (j == 12) { // belas
						val += 10;
					} else if (j == 13) { // puluh
						if (val / 10 != 0) { // cek dulu sebelumnya angkanya > 9 ato nggak
							val = val - temp2 + (temp2 * 10);
						} else { // kalau engga tinggal kali 10
							val *= 10;
						}
					} else { // ratus
						val *= 100;
					}
				}
			}
			j ++;
		}
		if (!found) { // jika bukan angka / belas / puluh / ratus
			if (val != 0) { // valuenya ga 0 brarti udah beres integernya
				printf("%d ", val);
				val = 0;
				flag = false;
			}
			int c;
			for (c = 0; c < currentWord.Length; c ++) { // print word (bukan angka)
				printf("%c", temp[c]);
			}
		} else { // masih angka / belas / puluh / ratus
			flag = true;
		}
		// nyimpen angka yang dibaca sebelumnya
		temp2 = (val % 100) % 10;

		ADVWORD();
		if (!endWord & !flag) { // spasi kalau bukan endWord dan bukan angka
			printf(" ");
		} else if (endWord) {
			if (val != 0) { // angka di akhir kalimat
				printf("%d", val);
			}
		}
	}
	printf("\n");

	return 0;
}