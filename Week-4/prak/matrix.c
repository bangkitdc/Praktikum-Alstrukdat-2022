// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

#include <stdio.h>
#include "matrix.h"
#include <math.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

   // ALGORITMA
   ROW_EFF(*m) = nRows;
   COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

   // ALGORITMA
   return (0 <= i && i < ROW_CAP) && (0 <= j && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */

   // ALGORITMA
   return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */

   // ALGORITMA
   return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

   // ALGORITMA
   return (0 <= i && i < ROW_EFF(m)) && (0 <= j && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */

   // AGORITMA
   return (ELMT(m, i, i));  
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */

   // ALGORITMA
   *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   createMatrix(nRow, nCol, m);
   for (i = 0; i < nRow; i ++) {
      for (j = 0; j < nCol; j ++) {
         scanf("%d", &ELMT(*m, i, j));
      }
   }
}

void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m); i ++) {
      for (j = 0; j < COL_EFF(m); j ++) {
         if (j == 0) {
            printf("%d", ELMT(m, i, j));
         } else {
            printf(" %d", ELMT(m, i, j));
         }
      }
      printf("\n");
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m1); i ++) {
      for (j = 0; j < COL_EFF(m1); j ++) {
         ELMT(m1, i, j) += ELMT(m2, i, j);
      }
   }  
   return m1;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m1); i ++) {
      for (j = 0; j < COL_EFF(m1); j ++) {
         ELMT(m1, i, j) -= ELMT(m2, i, j);
      }
   }  
   return m1;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */

   // KAMUS LOKAL
   int i, j, k;
   Matrix m3;
   IdxType r = COL_EFF(m1);
   // mxr . rxn = mxn

   // ALGORITMA
   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   for (i = 0; i < ROW_EFF(m1); i ++) {
      for (j = 0; j < COL_EFF(m2); j ++) {
         ELMT(m3, i, j) = 0;
         for (k = 0; k < r; k ++) {
            ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
         }
      }
   }
   return m3;
}

Matrix multiplyByConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
   
   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m); i ++) {
      for (j = 0; j < COL_EFF(m); j ++) {
         ELMT(m, i, j) *= x;
      }
   }
   return m;
}

void pMultiplyByConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

   // KAMUS LOKAL
   int i, j;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(*m); i ++) {
      for (j = 0; j < COL_EFF(*m); j ++) {
         ELMT(*m, i, j) *= k;
      }
   }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */

   // KAMUS LOKAL
   int i, j;
   boolean isEq = false;

   // ALGORITMA
   if (isMatrixSizeEqual(m1, m2)) {
      isEq = true;
      i = 0;
      while (i < ROW_EFF(m1) && isEq) {
         j = 0;
         while (j < COL_EFF(m1) && isEq) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
               isEq = false;
            } else {
               j += 1;
            }
         }
         i += 1;
      }
   }
   return isEq;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */

   // ALGORITMA
   return (!isMatrixEqual(m1, m2)); 
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

   // ALGORITMA
   return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */

   // ALGORITMA
   return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */

   // ALGORITMA
   return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */

   // KAMUS LOKAL
   int i, j;
   boolean isEq = false;

   // ALGORITMA
   if (isSquare(m)) {
      isEq = true;
      i = 0;
      while (i < ROW_EFF(m) && isEq) {
         j = 0;
         while (j < i && isEq) { //cek segitiga bawah
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
               isEq = false;
            }
            j += 1;
         }
         i += 1;
      }
   }
   return isEq;
}

boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */

   // KAMUS LOKAL
   int i, j;
   boolean idtt = false;

   // ALGORITMA
   if (isSquare(m)) {
      idtt = true;
      i = 0;
      while (i < ROW_EFF(m) && idtt) {
         j = 0;
         while (j < COL_EFF(m) && idtt) {
            if (i == j && ELMT(m, i, j) != 1) {
               idtt = false;
            } else if (i != j && ELMT(m, i, j) != 0) {
               idtt = false;
            }
            j += 1;
         }
      i += 1;
      }
   }
   return idtt;
}

boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

   // KAMUS LOKAL
   int i, j;
   ElType count = 0;

   i = 0;
   while (i < ROW_EFF(m) && (count * 100.0 / countElmt(m)) <= 5.0) {
      j = 0;
      while (j < COL_EFF(m) && (count * 100.0 / countElmt(m)) <= 5.0) {
         if (ELMT(m, i, j) != 0) {
            count += 1;
         }
         j += 1;
      }
      i += 1;
   }
   return (count * 100.0 / countElmt(m)) <= 5.0;
}

Matrix negation(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */

   // ALGORITMA
   pMultiplyByConst(&m, -1);
   return m;
}

void pNegation(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

   // ALGORITMA
   pMultiplyByConst(m, -1);
}

float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */

   // KAMUS LOKAL
   int i, j, p, im, jm;
   float res, cofactor;
   Matrix m2;

   // ALGORITMA (Recursive)
   if (ROW_EFF(m) == 1) {
      res = ELMT(m, 0, 0);
   } else if (ROW_EFF(m) == 2) {
      res = (ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0)); // ad - bc
   } else {
      // Cofactor Expansion
      res = 0;
      // Menggunakan ekspansi kofaktor baris pertama
      createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &m2);
      for (p = 0; p < COL_EFF(m); p ++) {
         im = 1; // index di matrix awal menggunakan im dan jm
         for (i = 0; i < ROW_EFF(m2); i ++) {
            jm = 0;
            for (j = 0; j < COL_EFF(m2); j ++) {
               if (jm == p) { // jika jm == p, maka bukan ini matrix kecilnya (yang akan dihitung determinannya)
                  jm += 1;
               }
               ELMT(m2, i, j) = ELMT(m, im, jm);
               jm += 1;
            }
            im += 1;
         }
         cofactor = pow(-1, p) * ELMT(m, 0, p) * determinant(m2);
         res += cofactor;     
      }
   }
   return res;
}

Matrix transpose(Matrix m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

   // KAMUS LOKAL
   int i, j;
   ElType temp; // karena isSquare, maka tidak perlu membuat matrix baru

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m); i ++) {
      for (j = 0; j < i; j ++) {
         temp = ELMT(m, i, j);
         ELMT(m, i, j) =  ELMT(m, j, i);
         ELMT(m, j, i) = temp;
      }
   }
   return m;
}

void pTranspose(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

   // KAMUS LOKAL
   int i, j;
   ElType temp; // karena isSquare, maka tidak perlu membuat matrix baru

   // ALGORITMA
   for (i = 0; i < ROW_EFF(*m); i ++) {
      for (j = 0; j < i; j ++) {
         temp = ELMT(*m, i, j);
         ELMT(*m, i, j) =  ELMT(*m, j, i);
         ELMT(*m, j, i) = temp;
      }
   } 
}

/* Operasi berbasis baris dan per kolom */ 

float AvgRow(Matrix m, IdxType i) {
   // KAMUS LOKAL
   int j;
   float res;

   // ALGORITMA
   res = 0;
   for (j = 0; j < COL_EFF(m); j ++) {
      res += ELMT(m, i, j);
   }
   return (res / (COL_EFF(m)));
}

float AvgCol(Matrix m, IdxType j) {
   // KAMUS LOKAL
   int i;
   float res;

   // ALGORITMA
   res = 0;
   for (i = 0; i < ROW_EFF(m); i ++) {
      res += ELMT(m, i, j);
   }

   return (res / (ROW_EFF(m)));
}

void MinMaxRow(Matrix m, IdxType i, ElType *max, ElType *min) {
   // KAMUS LOKAL
   int j;

   // ALGORITMA
   *max = ELMT(m, i, 0);
   *min = ELMT(m, i, 0);
   for (j = 0; j < COL_EFF(m); j ++) {
      if (ELMT(m, i, j) > *max) {
         *max = ELMT(m, i, j);
      }
      if (ELMT(m, i, j) < *min) {
         *min = ELMT(m, i, j);
      }
   }
}

void MinMaxCol(Matrix m, IdxType j, ElType *max, ElType *min) {
   // KAMUS LOKAL
   int i;

   // ALGORITMA
   *max = ELMT(m, 0, j);
   *min = ELMT(m, 0, j);
   for (i = 0; i < ROW_EFF(m); i ++) {
      if (ELMT(m, i, j) > *max) {
         *max = ELMT(m, i, j);
      }
      if (ELMT(m, i, j) < *min) {
         *min = ELMT(m, i, j);
      }
   }
}

int CountNumRow(Matrix m, IdxType i, ElType val) {
   // KAMUS LOKAL
   int j;
   int count = 0;

   // ALGORITMA
   for (j = 0; j < COL_EFF(m); j ++) {
      if (ELMT(m, i, j) == val) {
         count += 1;
      }
   }
   return count;
}

int CountNumCol(Matrix m, IdxType j, ElType val) {
   // KAMUS LOKAL
   int i;
   int count = 0;

   // ALGORITMA
   for (i = 0; i < ROW_EFF(m); i ++) {
      if (ELMT(m, i, j) == val) {
         count += 1;
      }
   }
   return count;
}

void RotateMat(Matrix *m) {
   int i;
   int left = 0;
   int up = 0;
   int right = COL_EFF(*m) - 1;
   int down = ROW_EFF(*m) - 1;
   int temp;

   while (left < right && up < down) { // reversed-rotate
      // up to down
      for (i = up; i < down; i ++) {
         temp = ELMT(*m, i, left);
         ELMT(*m, i, left) = ELMT(*m, i + 1, left);
         ELMT(*m, i + 1, left) = temp;
      }

      // left to right
      for (i = left; i < right; i ++) {
         temp = ELMT(*m, down, i);
         ELMT(*m, down, i) = ELMT(*m, down, i + 1);
         ELMT(*m, down, i + 1) = temp;
      }

      // down to up
      for (i = down; i > up; i --) {
         temp = ELMT(*m, i, right);
         ELMT(*m, i, right) = ELMT(*m, i - 1, right);
         ELMT(*m, i - 1, right) = temp;
      }

      // right to left (decrement by 1)
      for (i = right; i > left + 1; i --) {
         temp = ELMT(*m, up, i);
         ELMT(*m, up, i) = ELMT(*m, up, i - 1);
         ELMT(*m, up, i - 1) = temp;
      }
      left ++; up ++; down --; right --;
   }
}