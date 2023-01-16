// Nama : Muhammad Bangkit Dwi Cahyono
// NIM : 13521055

#include "boolean.h"
#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

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

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */

    // ALGORITMA
    return (l == NULL);
}

boolean isOneElmt(List l) {
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

    // ALGORITMA
    return (!isEmpty(l) && NEXT(l) == NULL);
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */

    // ALGORITMA
    return (INFO(l));
}

List tail(List l) {
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */

    // ALGORITMA
    return (isEmpty(l) ? l : NEXT(l));
}

List konso(List l, ElType e) {
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */

    // KAMUS LOKAL
    Address pnew;

    // ALGORITMA
    pnew = newNode(e);
    if (pnew != NULL) {
        NEXT(pnew) = l;
        l = pnew;
    }
    return l;
}

List konsb(List l, ElType e) {
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 

    // KAMUS LOKAL
    Address pnew, p;

    // ALGORITMA
    pnew = newNode(e);
    if (pnew != NULL) {
        if (isEmpty(l)) {
            return pnew;
        } else {
            NEXT(l) = konsb(tail(l), e);
            return l;
        }
    }
}

List copy(List l) {
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 

    // ALGORITMA
    if (isEmpty(l)) {
        return NULL;
    } else {
        return (konso(copy(tail(l)), head(l)));
    }
}

List concat(List l1, List l2) {
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

    // ALGORITMA
    if (isEmpty(l1)) {
        copy(l2);
    } else {
        return (konso(concat(tail(l1), l2), head(l1)));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l) {
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */

    // ALGORITMA
    if (isEmpty(l)) {
        return 0;
    } else {
        return (1 + length(NEXT(l)));
    }
}

boolean isMember(List l, ElType x) {
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */

    // ALGORITMA
    if (isEmpty(l)) {
        return false;
    } else {
        return (INFO(l) == x || isMember(NEXT(l), x));
    }
}

void displayList(List l) {
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

    // ALGORITMA
    if (!isEmpty(l)) {
        printf("%d\n", INFO(l));
        displayList(NEXT(l));
    }
}
