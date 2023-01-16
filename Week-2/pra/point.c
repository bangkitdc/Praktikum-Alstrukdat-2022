// Nama: Muhammad Bangkit Dwi C.
// NIM: 13521055

#include <stdio.h>
#include <math.h>
#include "point.h"
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
  
   // ALGORITMA
   Absis(*P) = X;
   Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
   
   // KAMUS LOKAL
   float x, y;

   // ALGORITMA
   scanf("%f %f", &x, &y);
   CreatePoint(P, x, y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
   
   // ALGORITMA
   printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
   
   // ALGORITMA
   return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
   
   // ALGORITMA
   return !EQ(P1, P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
   
   // ALGORITMA
   return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
   
   // ALGORITMA
   return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
   
   // ALGORITMA
   return (Absis(P) == 0);
}

int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
   
   // ALGORITMA
   return(
      (Absis(P) > 0 && Ordinat(P) > 0) ? 1 :
      (Absis(P) < 0 && Ordinat(P) > 0) ? 2 :
      (Absis(P) < 0 && Ordinat(P) < 0) ? 3 : 4
   );
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */              
   
   // ALGORITMA
   Absis(P) += 1;
   return P;
}

POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
   
   // ALGORITMA
   Ordinat(P) += 1;
   return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
   
   // ALGORITMA
   Absis(P) += deltaX;
   Ordinat(P) += deltaY;
   return P;
}

POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
   
   // ALGORITMA
   if (SbX) {
        Ordinat(P) *= -1;
    } else {
        Absis(P) *= -1;
    }
    return P;
}

float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
   
   // ALGORITMA
   return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
   
   // KAMUS LOKAL
   float x = Absis(P1) - Absis(P2);
   float y = Ordinat(P1) - Ordinat(P2);
   
   // ALGORITMA
   return (sqrt(pow(x, 2) + pow(y, 2)));
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
   
   // ALGORITMA
   *P = PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
   
   // ALGORITMA
   Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
   
   // ALGORITMA
   Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
   
   // ALGORITMA
   *P = MirrorOf(*P, SbX);
}

void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
   
   // KAMUS LOKAL
   float x = Absis(*P);
   float y = Ordinat(*P);
   float rad = Sudut * M_PI / 180;
   
   // ALGORITMA
   Absis(*P) = x * cos(rad) + y * sin(rad);
   Ordinat(*P) = - x * sin(rad) + y * cos(rad);
}
