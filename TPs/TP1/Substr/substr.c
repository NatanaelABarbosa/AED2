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
 * Recebe uma string e define um vetor de 26 posicoes e inicializa-o em 0, e n (variavel que definira o tamanho da substr). A string e transformada para apenas letras minusculas e ela e' iterada duas vezes, sendo que para cada i ate len, j = i e itera ate len, sendo len o tamanho do array. Com isso, a posicao referente a letra do alfabeto aumenta 1. Caso a posicao chegue a 2, significa que um valor repetiu, e desse modo o vetor e' limpo e a conta e' redefinida. Senao, o valor em n soma 1. Caso o valor em n seja maior que a variavel definida para retorno, res assume o valor de n. Para o fim da iteração em I, o vetor tambem e' redefinido.
 */
int count_substr(char * str) {
	int len = 0;
	int res = 0;
	int arr[26];
	int n = 0;

	if (str != NULL) {
		len = get_len(str); 
		to_lower(str);
		
		for (int i = 0; i < 26; arr[i] = 0, i++);

		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				arr[str[j] - 'a']++;
				if (arr[str[j] - 'a'] > 1){
					for (int k = 0; k < 26; arr[k] = 0, k++);
					n=0;
				} else {
					n++;
					if (n > res) res = n;
				}
			}	
			for (int k = 0; k < 26; arr[k] = 0, k++);		
			n = 0;
		}	
	}
	return res;
}

int main () {
	char str [100];

	scanf("%s", str);
	while (compare(str, "FIM") != 0) {
		printf("%d\n", count_substr(str));
		scanf("%s", str);
	}

	return 0;
}

