/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include "boolean.h"
#include <stdio.h>
#include "prioqueuetime.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (PrioQueueTime Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	return ((Tail(Q) + 1) % MaxEl(Q) == Head(Q));
}
int NBElmt (PrioQueueTime Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmpty(Q)) {
		return 0;
	} else if (IsFull(Q)) {
		return MaxEl(Q);
	} else {
		return ((Tail(Q) + MaxEl(Q) - Head(Q) + 1) % MaxEl(Q));
	}
}
/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T = (infotype *) malloc (sizeof(infotype) * (Max));
	if ((*Q).T) {
		MaxEl(*Q) = Max;
	} else {
		MaxEl(*Q) = 0;
	}
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	MaxEl(*Q) = 0;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
 	int i, j;
 	infotype t;
 	boolean found;
 	
 	if (IsEmpty(*Q)) { // jika kosong langsung tambah
		Head(*Q) = Tail(*Q) = 0;
		InfoTail(*Q) = X;
	} else { // jika tidak, liat kasusnya
		// tambah 1 space di belakang
		Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
		
		found = false;
		for (i = 0; i < NBElmt(*Q) - 1; i ++) { // kurang 1 soalnya tailnya udah ditambah 1
			// searching dari elemen head
			t = Elmt(*Q, (i + Head(*Q)) % MaxEl(*Q));
			// jika X.time > t.time
			if (Time(X) < Time(t)) {
				// pindah semua->kanan				
				for (j = (Tail(*Q) - 1) % MaxEl(*Q); j >= (i + Head(*Q)) % MaxEl(*Q); j --) {
					Elmt(*Q, j + 1) = Elmt(*Q, j);
				}
				Elmt(*Q, (i + Head(*Q) % MaxEl(*Q))) = X;
				found = true;
				break;
			}
		}
		// handle kalau ga ketemu
		if (!found) {
			InfoTail(*Q) = X;
		}
	}
}

void Dequeue (PrioQueueTime * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
	*X = InfoHead(*Q);
	if (NBElmt(*Q) == 1) {
		Head(*Q) = Tail(*Q) = Nil;
	} else {
		Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
	}
}

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q) {
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
	int i;
	for (i = 0; i < NBElmt(Q); i ++) {
		// printf("%d %c\n", Elmt(Q, (i + Head(Q)) % MaxEl(Q)).time, Elmt(Q, (i + Head(Q)) % MaxEl(Q)).info);
		printf("%d %c\n", Time(Elmt(Q, (i + Head(Q)) % MaxEl(Q))), Info(Elmt(Q, (i + Head(Q)) % MaxEl(Q))));
	}
	printf("#\n");
}

