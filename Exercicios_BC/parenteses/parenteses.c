#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verify(char * str) {
	bool res = false;
	char tmp[1000];
	int j = 0;
	int n = 0;
	char c = '0';
		
	for (int i = 0; i < strlen(str); i++) {
		c = str[i];
		if (c == '(' || c == ')') tmp[j++] = c;
	}

	if (j % 2 == 0) {
		for (int i = 0; i < j; i++) {
			if (tmp[i] == '(') {
				for (int k = i+1; k < j; k++) 
					if (tmp[k] == ')') 
					{ tmp[i] = tmp[k] = '*'; n+=2; k = j; }		
			}
		}

		if (n==j) res = true;
	}

	return res;
}	

int main (void) {
	char str [10000];

	while (scanf("%[^\n]", str) == 1) {
		getchar();
	
		if (verify(str)) printf("correct\n");
		else printf("incorrect\n");	
	}

	return 0;
}
