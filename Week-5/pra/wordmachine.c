// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

#include "boolean.h"
#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

   // ALGORITMA
   while (currentChar == BLANK) {
      ADV();
   }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

   // ALGORITMA
   START();
   IgnoreBlanks();
   if (currentChar == MARK) {
      EndWord = true;
   } else {
      EndWord = false;
      CopyWord();
   }

}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

   // ALGORITMA
   IgnoreBlanks();
   if (currentChar == MARK) {
      EndWord = true;
   } else {
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

   // ALGORITMA
   currentWord.Length = 0;
   while (currentChar != BLANK && currentChar != MARK) {
      if (currentWord.Length < NMax) {
         currentWord.TabWord[currentWord.Length] = currentChar;
         currentWord.Length += 1;
         ADV();
      } else {
         break;
      }
   }
}
