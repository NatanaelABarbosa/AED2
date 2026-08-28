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
 * Recebe uma string e troca letras maiusculas por minusculas
 */
void to_lower(char * str) {
	int len = get_len(str);
	for (int i = 0; i < len; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') str[i]+=('a'-'A');
	}
}

/**
 * Recebe duas strings e cria dois vetores com tamanho 26. Se os tamanhos das strings forem iguais, inicializa os vetores com 0 e usa a funcao to_lower() nas duas. Após, soma a posicao do array correspondente a posicao da letra do alfabeto de cada caractere das strings correspondentes.
 */
int is_anagram(char * str1, char * str2) {
	int res = 0;
	int arr1[26];
	int arr2[26];

	if (str1 != NULL && str2 != NULL) {
		res=1;
		int len1 = get_len(str1);
		int len2 = get_len(str2);
		if (len1 == len2) {
			to_lower(str1); to_lower(str2);
			for (int i = 0; i < 26; i++) { arr1[i] = 0; arr2[i] = 0;}
		
			for (int i = 0; i < len1; i++) {
				arr1[str1[i] - 'a']++;
				arr2[str2[i] - 'a']++;
			}

			res = 0;
			for (int i = 0; i < 26; i++) {
				if (arr1[i] != arr2[i]) { res++; i=26; }	
			}
		}
	}

	return res;
}

int main () {
	char str1[100] = "";
	char str2[100] = "";
	int n = 0;

	scanf("%s %s", str1, str2);
	while (compare(str1, "FIM") != 0) {
		n = is_anagram(str1, str2);
		
		if (n == 1) printf("NAO\n");
		else printf("SIM\n");
		scanf("%s %s", str1, str2);
	}

	return 0;
}

