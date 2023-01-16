// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "boolean.h"
#include <stdio.h>
#include "listdin.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

   // ALGORITMA
   BUFFER(*l) = malloc(capacity * sizeof(ElType));
   NEFF(*l) = 0;
   CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

   // ALGORITMA
   free(BUFFER(*l));
   CAPACITY(*l) = 0;
   NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */ 

   // ALGORITMA
   return (NEFF(l));
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

   // ALGORITMA
   return (IDX_MIN);
}

IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

   // ALGORITMA
   return (listLength(l) - 1); 
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/ 

   // ALGORITMA
   return (0 <= i && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

   // ALGORITMA
   return (0 <= i && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

   // ALGORITMA
   return (!listLength(l));
}

/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

   // ALGORITMA
   return (listLength(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */

   // KAMUS LOKAL
   int N, i;

   // ALGORITMA
   scanf("%d", &N);
   while (!(0 <= N && N <= CAPACITY(*l))) {
      scanf("%d", &N);
   }
   for (i = 0; i < N; i ++) {
      scanf("%d", &ELMT(*l, i));
   }
   NEFF(*l) = N;
}

void printList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   printf("[");
   if (listLength(l) > 0) {
      printf("%d", ELMT(l, 0));
      for (i = 1; i < listLength(l); i ++) {
         printf(",%d", ELMT(l, i));
      }
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

   // KAMUS LOKAL
   int i;
   ListDin res; //Karena memanfaatkaan heap memory, harus membuat list baru

   // ALGORITMA
   // cara 1
   copyList(l1, &res);
   // cara 2
   // CreateListDin(&res, CAPACITY(l1));
   // NEFF(res) = NEFF(l1);

   if (plus) {
      for (i = 0; i < listLength(l1); i ++) {
         ELMT(res, i) = ELMT(l1, i) + ELMT(l2, i);
      }
   } else {
      for (i = 0; i < listLength(l1); i ++) {
         ELMT(res, i) = ELMT(l1, i) - ELMT(l2, i);
      }
   }
   return res;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

   // KAMUS LOKAL
   int i = 0;
   boolean flag = true;

   // ALGORITMA
   if (listLength(l1) != listLength(l2)) {
      flag = false;
   } else {
      while (i < listLength(l1) && flag) {
         if (ELMT(l1, i) != ELMT(l2, i)) {
            flag = false;
         }
         i += 1;
      }
   }
   return flag;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

   // KAMUS LOKAL
   int i = 0;
   boolean found = false;

   // ALGORITMA
   while (i < listLength(l) && !found) {
      if (ELMT(l, i) == val) {
         found = true;
      } else {
         i += 1;
      }
   }
   return (
      (found) ? i : IDX_UNDEF
   );
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   *max = ELMT(l, 0);
   *min = ELMT(l, 0);
   for (i = 0; i < listLength(l); i ++) {
      if (ELMT(l, i) > *max) {
         *max = ELMT(l, i);
      }
      if (ELMT(l, i) < *min) {
         *min = ELMT(l, i);
      }
   }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   CreateListDin(lOut, CAPACITY(lIn));
   NEFF(*lOut) = NEFF(lIn);
   for (i = 0; i < listLength(lIn); i ++) {
      ELMT(*lOut, i) = ELMT(lIn, i);
   }
}

ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */

   // KAMUS LOKAL
   int i;
   ElType sum = 0;

   // ALGORITMA
   for (i = 0; i < listLength(l); i ++) {
      sum += ELMT(l, i);
   }
   return sum;
}

int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

   // KAMUS LOKAL
   int i;
   int count = 0;

   // ALGORITMA
   for (i = 0; i < listLength(l); i ++) {
      if (ELMT(l, i) == val) {
         count += 1;
      }
   }
   return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

   // KAMUS LOKAL
   int i, j;
   ElType temp;
   boolean flag = false;

   // ALGORITMA
   // Optimized Bubble Sort <3
   for (i = 0; i < listLength(*l) - 1; i ++) {
      for (j = i + 1; j < listLength(*l); j ++) {
         if (
            (asc && ELMT(*l, i) > ELMT(*l, j)) ||
            (!asc && ELMT(*l, i) < ELMT(*l, j))
         ) {
            temp = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, j);
            ELMT(*l, j) = temp;
            flag = true;
         }
      }
      if (!flag) {
         break;
      }
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

   // ALGORITMA
   ELMT(*l, listLength(*l)) = val;
   NEFF(*l) += 1; 
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

   // ALGORITMA
   *val = ELMT(*l, listLength(*l) - 1);
   NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

   // ALGORITMA
   CAPACITY(*l) += num;
   BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

   // ALGORITMA
   CAPACITY(*l) -= num;
   BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l){
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

   // ALGORITMA
   CAPACITY(*l) = listLength(*l);
   BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType) * CAPACITY(*l));
}
