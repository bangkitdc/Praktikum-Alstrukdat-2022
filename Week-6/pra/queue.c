// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055
/* File : queue.h */
/* Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik */

#include "boolean.h"
#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
	
	// ALGORITMA
	IDX_HEAD(*q) = IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
	
	// ALGORITMA
	return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

	// ALGORITMA
	return ((IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q)); 
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

	// ALGORITMA
	if (isEmpty(q)) {
		return 0;
	} else if (isFull(q)) {
		return CAPACITY;
	} else {
		return ((IDX_TAIL(q) + CAPACITY - IDX_HEAD(q) + 1) % CAPACITY);
	}
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

	// ALGORITMA
	if (isEmpty(*q)) {
		IDX_HEAD(*q) = IDX_TAIL(*q) = 0;
	} else {
		IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
	}
	TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

	// ALGORITMA
	*val = HEAD(*q);
	if (length(*q) == 1) {
		IDX_HEAD(*q) = IDX_TAIL(*q) = IDX_UNDEF;
	} else {
		IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
	}
}

/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

	// KAMUS LOKAL
	int i;

	// ALGORITMA
	printf("[");

	if (!isEmpty(q)) {
		for (i = 0; i < length(q); i ++) {
			printf("%d", (q).buffer[(i + IDX_HEAD(q)) % CAPACITY]);
			if ((i + IDX_HEAD(q)) % CAPACITY != IDX_TAIL(q)) {
				printf(",");
			}
		}
	}

	printf("]\n");
}
