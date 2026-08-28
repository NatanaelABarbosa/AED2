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
 * Recebe uma string para criptografá-la somando o caractere com o valor cod. o inteiro i define o indice do caractere da string.
 */
void cesar (char * str, int i, int cod) {
	if (str[i] != '\0') {
		str[i] = str[i]+cod;
		cesar(str, i+1, 3);
	}
}

int main () {
	char str [1000];
	
	scanf("%[^\n]", str); getchar();
	while (compare(str, "FIM") != 0) {
		cesar(str, 0, 3);
		printf("%s\n", str);
		scanf("%[^\n]", str); getchar();
	}

	return 0;
}

