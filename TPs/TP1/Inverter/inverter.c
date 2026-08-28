/**
 * @author Natanael Barbosa
 */
#include <stdio.h>

int get_len(char * str) {
	int res = 0;
	
	while (str[res] != '\0') res++;

	return res;
}

int compare (char * str1, char * str2) {
	int res = 0;

	if (str1 != NULL && str2 != NULL) {
		if (get_len(str1) != get_len(str2)) res++;
		else {
			for (int i = 0; i < get_len(str1); i++) {
				if (str1[i] != str2[i]) { res++; i = get_len(str1); }
			}
		}
	}

	return res;
}

/**
 * Recebe duas strings, inverte a primeira e coloca o resultado na segunda. Para isso, itera a string original e adiciona na outra string cada caractere n-i-1 da string original no indice i da nova string.
 */
void invert (char * str, char * res) {
	if (str != NULL) {
		int len = get_len(str);
		for (int i = 0; i < len; i++) {
			res[i] = str[len-i-1];
		}
		res[len] = '\0';
	}
}

int main (void) {
	char str [500] = "";
	char res [500] = "";

	scanf("%[^\n]", str); getchar();
	while (compare(str, "FIM") != 0) {
		invert(str, res);
		printf("%s\n", res);
		scanf("%[^\n]", str); getchar();
	}
	return 0;
}

