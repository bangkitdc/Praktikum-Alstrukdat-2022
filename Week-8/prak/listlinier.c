// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* NODE */
Address newNode(ElType val) {
    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

    // ALGORITMA
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */

    // ALGORITMA
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

    // KAMUS LOKAL
    int counter;
    Address p;

    // ALGORITMA
    counter = 0;
    p = FIRST(l);
    while (counter < idx) {
        counter += 1;
        p = NEXT(p);
    }
    return (INFO(p));
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

    // KAMUS LOKAL
    int counter;
    Address p;

    // ALGORITMA
    counter = 0;
    p = FIRST(*l);
    while (counter < idx) {
        counter += 1;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

    // KAMUS LOKAL
    int i;
    Address p;
    boolean found;

    // ALGORITMA
    p = FIRST(l);
    found = false;
    i = 0;

    while (p != NULL && !found) {
        if (INFO(p) == val) {
            found = true;
        } else {
            i += 1;
            p = NEXT(p);
        }
    }

    if (found) {
        return (i);
    } else {
        return (IDX_UNDEF);
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

    // KAMUS LOKAL
    Address pNew;

    // ALGORITMA
    pNew = newNode(val);
    if (pNew != NULL) {
        NEXT(pNew) = FIRST(*l);
        FIRST(*l) = pNew;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    // KAMUS LOKAL
    Address loc, pNew;

    // ALGORITMA
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        pNew = newNode(val);
        if (pNew != NULL) {
            loc = FIRST(*l);
            while (NEXT(loc) != NULL) {
                loc = NEXT(loc);
            }
            NEXT(loc) = pNew;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    // KAMUS LOKAL
    int counter;
    Address pNew, loc;

    // ALGORITMA
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        pNew = newNode(val);
        if (pNew != NULL) {
            counter = 0;
            loc = FIRST(*l);
            while (counter < idx - 1) {
                counter += 1;
                loc = NEXT(loc);
            }
            NEXT(pNew) = NEXT(loc);
            NEXT(loc) = pNew;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

    // KAMUS LOKAL
    Address loc;

    // ALGORITMA
    loc = FIRST(*l);
    *val = INFO(loc);
    FIRST(*l) = NEXT(loc);
    free(loc);
}

void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

    // KAMUS LOKAL
    Address pDel, loc;

    // ALGORITMA
    pDel = FIRST(*l);
    loc = NULL;
    while (NEXT(pDel) != NULL) {
        loc = pDel;
        pDel = NEXT(pDel);
    }
    if (loc == NULL) { // length = 1
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(pDel);
    free(pDel);
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

    // KAMUS LOKAL
    int counter;
    Address pDel, loc;

    // ALGORITMA
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        counter = 0;
        loc = FIRST(*l);
        while (counter < idx - 1) {
            counter += 1;
            loc = NEXT(loc);
        }
        pDel = NEXT(loc);
        *val = INFO(pDel);
        NEXT(loc) = NEXT(pDel);
        free(pDel);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
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
        while (p != NULL) {
            printf(",%d", INFO(p));
            p = NEXT(p);
        }
    }
    printf("]");
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    // KAMUS LOKAL
    int counter;
    Address p;

    // ALGORITMA
    if (isEmpty(l)) {
        return 0;
    } else {
        counter = 0;
        p = FIRST(l);
        while (p != NULL) {
            counter += 1;
            p = NEXT(p);
        }
        return counter;
    }
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

    // KAMUS LOKAL
    Address p;
    List lRes;

    // ALGORITMA
    CreateList(&lRes);
    p = FIRST(l1);
    while (p != NULL) {
        insertLast(&lRes, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&lRes, INFO(p));
        p = NEXT(p);
    }
    return lRes;
}

boolean fSearch(List L, Address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
	Address p;
	boolean found;
	
	found = false;
	p = FIRST(L);
	while (p != NULL && !found) {
		if (p == P) {
			found = true;
		} else {
			p = NEXT(p);
		}
	}
	if (P == NULL) {
		found = true;
	}
	return found;
}

Address searchPrec(List L, ElType X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
	Address p, pprev;
	boolean found;
	
	p = FIRST(L);
	found = false;
	pprev = NULL;
	while (p != NULL && !found) {
		if (INFO(p) == X) {
			found = true;
		} else {
			pprev = p;
			p = NEXT(p);
		}
	}
	if (found) {
		return pprev;
	} else {
		return NULL;
	}
} 

/*** Prekondisi untuk Max/Min : List tidak kosong ***/
ElType max(List l){
/* Mengirimkan nilai info(P) yang maksimum */
	Address p;
	ElType max;
	
	p = FIRST(l);
	max = INFO(p); // first element
	p = NEXT(p);
	while (p != NULL) {
		if (INFO(p) > max) {
			max = INFO(p);
		}
		p = NEXT(p);
	}
	return max;
}

Address adrMax(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
	Address p, pMax;
	ElType max;
	
	p = FIRST(l);
	max = INFO(p); // first e
	pMax = p;
	p = NEXT(p);
	
	while (p != NULL) {
		if (INFO(p) > max) {
			max = INFO(p);
			pMax = p;
		}
		p = NEXT(p);
	}
	
	return pMax;
}

ElType min(List l){
/* Mengirimkan nilai info(P) yang minimum */
	Address p;
	ElType min;
	
	p = FIRST(l);
	min = INFO(p); // first element
	p = NEXT(p);
	while (p != NULL) {
		if (INFO(p) < min) {
			min = INFO(p);
		}
		p = NEXT(p);
	}
	return min;
}

Address adrMin(List l) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
	Address p, pMin;
	ElType min;
	
	p = FIRST(l);
	min = INFO(p); // first e
	pMin = p;
	p = NEXT(p);
	
	while (p != NULL) {
		if (INFO(p) < min) {
			min = INFO(p);
			pMin = p;
		}
		p = NEXT(p);
	}
	
	return pMin;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
	Address p;
	int i, val;
	
	int len = length(*l);
	
	for (i = 0; i < len; i ++) {
		deleteFirst(l, &val);
	}
}

void copyList(List *l1, List *l2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
	FIRST(*l2) = FIRST(*l1);
}

void inverseList(List *l) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
	Address p, pNext;
	
	p = FIRST(*l);
	if (p != NULL) {
		pNext = NEXT(p);
		NEXT(p) = NULL;
		p = pNext;
		while (p != NULL) { //lebih dari 1 elemen
			pNext = NEXT(p);
			NEXT(p) = FIRST(*l);
			FIRST(*l) = p;
			p = pNext;
		}
	}
}

void splitList(List *l1, List *l2, List l) {
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
	Address p;
	CreateList(l1);
	CreateList(l2);

	int i, j;	

	p = FIRST(l);
	for (i = 0; i < (length(l) / 2); i ++) {
		insertLast(l1, INFO(p));
		p = NEXT(p);
	}
	for (j = 0; j < length(l) - (length(l) / 2); j ++) {
		insertLast(l2, INFO(p));
		p = NEXT(p);
	}
}

