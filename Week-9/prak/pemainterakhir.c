#include <stdio.h>
#include "list_circular.h"

int main(){
 	int n, k;
 	scanf("%d", &n);
 	scanf("%d", &k);
 
 	List l;
 	CreateList(&l);
 	int i;
 
 	for (i = 0; i < n; i ++) {
  		insertLast(&l, i + 1);
 	}

 	ElType val;
 	int j, p;
 	for (j = 0; j < n - 1; j ++) {
 		for (p = 0; p < k; p ++) {
 			FIRST(l) = NEXT(FIRST(l));
 		}
 		deleteLast(&l, &val);
 		printf("%d\n", val);
 	}
 
 	printf("Pemenang %d\n", INFO(FIRST(l)));
}