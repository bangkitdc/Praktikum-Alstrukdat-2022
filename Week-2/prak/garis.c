// Nama: Muhammad Bangkit Dwi C.
// NIM: 13521055

/* *** ADT LAIN YANG DIPAKAI *** */
#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
#include "garis.h"
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void CreateGaris (GARIS * L, POINT P1, POINT P2){
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */  
   
   // ALGORITMA
   PAwal(*L) = P1;
   PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

   // KAMUS LOKAL
   POINT P1, P2;

   // ALGORITMA
   BacaPOINT(&P1);
   BacaPOINT(&P2);
   while(EQ(P1, P2)) {
      printf("Garis tidak valid\n");
      BacaPOINT(&P1);
      BacaPOINT(&P2);
   }

   CreateGaris(L, P1, P2);
}

void TulisGARIS (GARIS L){
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

   // ALGORITMA
   printf("(");
   TulisPOINT(PAwal(L));
   printf(",");
   TulisPOINT(PAkhir(L));
   printf(")");
}


/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
/* Menghitung panjang garis L : berikan rumusnya */
   
   // KAMUS LOKAL
   POINT P1 = PAwal(L); POINT P2 = PAkhir(L);

   // ALGORITMA
   float x = Absis(P1) - Absis(P2);
   float y = Ordinat(P1) - Ordinat(P2);

   return sqrt(pow(x, 2) + pow(y, 2));
}

float Gradien (GARIS L){
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */

   // KAMUS LOKAL
   POINT P1 = PAwal(L); POINT P2 = PAkhir(L);

   // ALGORITMA
   return (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
   Geser(&PAwal(*L), deltaX, deltaY);
   Geser(&PAkhir(*L), deltaX, deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */

   // ALGORITMA
   return(
      (Gradien(L1) * Gradien(L2) == -1) ? 1 : 0
      );
}

boolean IsSejajar (GARIS L1, GARIS L2){
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */

   // ALGORITMA
   return (Gradien(L1) == Gradien(L2));
}

