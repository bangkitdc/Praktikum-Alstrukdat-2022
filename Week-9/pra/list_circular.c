// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"

/* Definisi List Circular : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
	
	// ALGORITMA
	return (FIRST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

	// ALGORITMA
	FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

	// KAMUS LOKAL
	Address p;

	// ALGORITMA
	p = (Address) malloc(sizeof(ElmtList));
	if (p != NULL) {
		INFO(p) = val;
		NEXT(p) = NULL;
	}
	return p;
}

void deallocate(Address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

	// ALGORITMA
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

	// KAMUS LOKAL
	Address p;

	// ALGORITMA
	p = FIRST(l);
	if (isEmpty(l)) {
		return NULL;
	} else {
		while (NEXT(p) != FIRST(l) && INFO(p) != val) { // biar ga looping terus2an
			p = NEXT(p);
		}
		if (INFO(p) == val) { // p = last elemen/ INFO(p) == val
			return p;
		} else {
			return NULL;
		}
	}
}

boolean addrSearch(List l, Address p) {
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

	// KAMUS LOKAL
	Address q;

	// ALGORITMA
	q = FIRST(l);
	if (isEmpty(l)) {
		return false;
	} else {
		while (NEXT(q) != FIRST(l) && q != p) { // biar ga looping terus2an
			q = NEXT(q);
		}
		return (q == p);
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */

	// KAMUS LOKAL
	Address p, pnew;

	// ALGORITMA
	pnew = allocate(val);
	if (pnew != NULL) {
		if (isEmpty(*l)) {
			NEXT(pnew) = pnew;
		} else {
			p = FIRST(*l);
			while (NEXT(p) != FIRST(*l)) { // last element
				p = NEXT(p);
			}

			NEXT(pnew) = FIRST(*l);
			NEXT(p) = pnew;
		}
		FIRST(*l) = pnew;
	}
}

void insertLast(List *l, ElType val) {
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

	// KAMUS LOKAL
	Address p, pnew;

	// ALGORITMA
	if (isEmpty(*l)) {
		insertFirst(l, val);
	} else {
		pnew = allocate(val);
		if (pnew != NULL) {
			p = FIRST(*l);
			while (NEXT(p) != FIRST(*l)) { // last element
				p = NEXT(p);
			}
			NEXT(p) = pnew;
			NEXT(pnew) = FIRST(*l);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val) {
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */

	// KAMUS LOKAL
	Address p, pdel;

	// ALGORITMA
	pdel = FIRST(*l); *val = INFO(pdel);
	if (NEXT(FIRST(*l)) == FIRST(*l)) { // hanya 1 element
		FIRST(*l) = NULL;
	} else {
		p = FIRST(*l);
		while (NEXT(p) != FIRST(*l)) { // ke last element
			p = NEXT(p);
		}
		FIRST(*l) = NEXT(FIRST(*l)); 
		NEXT(p) = FIRST(*l);
	}
	deallocate(pdel);
}

void deleteLast(List *l, ElType * val) {
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */

	// KAMUS LOKAL
	Address p, pprev;

	// ALGORITMA
	pprev = NULL;
	p = FIRST(*l);

	while (NEXT(p) != FIRST(*l)) { // ke last element
		pprev = p;
		p = NEXT(p);
	}
	if (pprev == NULL) {
		FIRST(*l) = NULL;
	} else {
		NEXT(pprev) = FIRST(*l);
	}
	*val = INFO(p);
	deallocate(p);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

	// KAMUS LOKAL
	Address p;

	// ALGORITMA
	printf("[");
	if (!isEmpty(l)) {
		p = FIRST(l);
		printf("%d", INFO(p));
		p = NEXT(p);
		while (p != FIRST(l)) {
			printf(",%d", INFO(p));
			p = NEXT(p);
		}
	}
	printf("]");
}