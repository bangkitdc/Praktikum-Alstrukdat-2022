// NIM: 13521055
// Nama: Muhammad Bangkit Dwi Cahyono

#include "boolean.h"
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) { 
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

   // KAMUS LOKAL
   BinTree p;

   // ALGORITMA
   p = (BinTree) malloc(sizeof(TreeNode));
   if (p != NULL) {
      ROOT(p) = root;
      LEFT(p) = left_tree;
      RIGHT(p) = right_tree;
   }

   return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

   // ALGORITMA
   *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val) {
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

   // KAMUS LOKAL
   Address p;

   // ALGORITMA
   p = (Address) malloc(sizeof(TreeNode));
   if (p != NULL) {
      ROOT(p) = val;
      LEFT(p) = NULL;
      RIGHT(p) = NULL;
   }

   return p;
}

void deallocTreeNode (Address p) {
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

   // ALGORITMA
   free(p);
}

boolean isTreeEmpty (BinTree p) {
/* Mengirimkan true jika p adalah pohon biner yang kosong */

   // ALGORITMA
   return (p == NULL);
}

boolean isOneElmt (BinTree p) {
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

   // ALGORIMTA
   if (isTreeEmpty(p)) {
      return false;
   } else {
      return (LEFT(p) == NULL && RIGHT(p) == NULL);
   }
}

boolean isUnerLeft (BinTree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
   
   // ALGORITMA
   if (isTreeEmpty(p)) {
      return false;
   } else {
      return (LEFT(p) != NULL && RIGHT(p) == NULL);
   }
}

boolean isUnerRight (BinTree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

   // ALGORITMA
   if (isTreeEmpty(p)) {
      return false;
   } else {
      return (LEFT(p) == NULL && RIGHT(p) != NULL);
   }
}

boolean isBinary (BinTree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

   // ALGORITMA
   if (isTreeEmpty(p)) {
      return false;
   } else {
      return (LEFT(p) != NULL && RIGHT(p) != NULL);
   }
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

   // ALGORITMA
   printf("(");
   if (!isTreeEmpty(p)) {
      printf("%d", ROOT(p));
      printPreorder(LEFT(p));
      printPreorder(RIGHT(p));
   }
   printf(")");
}

void printInorder(BinTree p) {
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

   // ALGORITMA
   printf("(");
   if (!isTreeEmpty(p)) {
      printInorder(LEFT(p));
      printf("%d", ROOT(p));
      printInorder(RIGHT(p));
   }
   printf(")");
}

void printPostorder(BinTree p) {
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

   // ALGORITMA
   printf("(");
   if (!isTreeEmpty(p)) {
      printPostorder(LEFT(p));
      printPostorder(RIGHT(p));
      printf("%d", ROOT(p));
   }
   printf(")");
}

void printPreorderIndentNL(BinTree p, int depth, int h) {
/* I.S. p terdefinisi, depth >= 0, h >= 0 */
/* F.S. Semua simpul p sudah dicetak secara preorder: ROOT - LEFT - RIGHT. 
        Setiap root dipisahkan dengan baris baru.
        Untuk setiap root akan ditulis indentasi sebanyak (depth * h) spasi. */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   if (!isTreeEmpty(p)) {
      for (i = 0; i < depth * h; i++) { // first level (no indentations)
         printf(" ");
      }
      printf("%d\n", ROOT(p));
      printPreorderIndentNL(LEFT(p), depth + 1, h);
      printPreorderIndentNL(RIGHT(p), depth + 1, h);
   }
}

void printTree(BinTree p, int h) {
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/

   // Depth mulai dari 0, level pertama tidak ada indentasi
   printPreorderIndentNL(p, 0, h);
}


int rob1(BinTree root) {
	int kiri, kanan;
	if (isTreeEmpty(root)) {
		return 0;
	} else {
		kiri = rob1(LEFT(root));
		kanan = rob1(RIGHT(root));
		if (kiri > kanan) {
			return ROOT(root) + kiri;
		} else {
			return ROOT(root) + kanan;
		}
	}
}

int rob2Count(BinTree root, boolean available) {
   // available -> true, rootnya bisa diambil
   // available -> false, yang dihitung yang di bawahnya (skip)

   // KAMUS LOKAL
   int skipRec, robRec;

   // ALGORITMA
   if (isTreeEmpty(root)) {
      return 0;
   }

   // Saat ROOT di skip
   skipRec = rob2Count(LEFT(root), true) + rob2Count(RIGHT(root), true);

   // Jika Available dibandingin antara ROOT dengan bawahnya (skipRec)
   if (available) {
      robRec = rob2Count(LEFT(root), false) + rob2Count(RIGHT(root), false) + ROOT(root);

      if (skipRec > robRec) {
         return skipRec;
      } else {
         return robRec;
      }
   
   }
   return skipRec;
}

int rob2(BinTree root) {
   return rob2Count(root, true);
}

