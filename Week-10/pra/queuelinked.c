// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

#include "boolean.h"
#include "queuelinked.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
Address newNode(ElType x) {
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */

    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}

int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

    // KAMUS LOKAL
    Address p;
    int count;

    // ALGORITMA
    count = 0;
    p = ADDR_HEAD(q);
    while (p != NULL) {
        count += 1;
        p = NEXT(p);
    }
    return count;
}

/*** Kreator ***/
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

    // ALGORITMA
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q) {
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    printf("[");
    if(!isEmpty(q)) {
        p = ADDR_HEAD(q);
        printf("%d", INFO(p));
        p = NEXT(p);
        while (p != NULL) {
            printf(",%d", INFO(p));
            p = NEXT(p);
        }
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x) {
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */

    // KAMUS LOKAL
    Address pnew;

    // ALGORITMA
    pnew = newNode(x);
    if (pnew != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = pnew;
            ADDR_TAIL(*q) = pnew;
        } else {
            NEXT(ADDR_TAIL(*q)) = pnew;
            ADDR_TAIL(*q) = pnew;
        }
    }
}

void dequeue(Queue *q, ElType *x) {
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */

    // KAMUS LOKAL
    Address p;

    // ALGORITMA
    p = ADDR_HEAD(*q);
    *x = INFO(p);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q)) { // 1 element
        ADDR_HEAD(*q) = NULL;
        ADDR_TAIL(*q) = NULL;
    } else {
        ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    }

    free(p);
}
