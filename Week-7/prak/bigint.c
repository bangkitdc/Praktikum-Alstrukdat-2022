#include <stdio.h>
#include "stack.h"

int main() {
	Stack S1, S2, SPlus;
	int i, carry, a, b, res;
	char str[100];

	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&SPlus);

	// first num
	scanf("%s", &str);
	i = 0;
	while (str[i] != '#') {
		Push(&S1, str[i] - '0');
		i += 1;
	}

	// second num
	scanf("%s", &str);
	i = 0;
	while (str[i] != '#') {
		Push(&S2, str[i] - '0');
		i += 1;
	}

	carry = 0;
	// SPlus
	while(!IsEmpty(S1) || !IsEmpty(S2)) {
		// Mengambil elemen dari top(S1) dan top(S2)
		if (!IsEmpty(S1)) {
			Pop(&S1, &a);
		} else {
			a = 0;
		}
		if (!IsEmpty(S2)) {
			Pop(&S2, &b);	
		} else {
			b = 0;
		}
		res = a + b + carry;
		Push(&SPlus, res % 10);
		if (res > 9) { 
			carry = 1;
		} else {
			carry = 0;
		}
	}
	// add carry
	if (carry == 1) {
        Push(&SPlus, 1);
    }

    // print result (reversely)
    while(!IsEmpty(SPlus)) {
    	Pop(&SPlus, &res);
    	printf("%d", res);
    }
    printf("\n");

	return 0;
}