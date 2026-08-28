/**
 * @author Natanael Barbosa
 */
#include <stdio.h>

void get_len(char * str, int * i) {
	if (str[*i] != '\0') {
		(*i)++;
		return get_len(str, i);
	}
}

int compare (char * str1, char * str2) {
	int res = 0;
	int i = 0;
	int j = 0;

	if (str1 != NULL && str2 != NULL) {
		get_len(str1, &i);
		get_len(str2, &j);
		if (i != j) res++;
		else {
			for (int k = 0; k < i; k++) {
				if (str1[k] != str2[k]) { res++; k = i; }
			}
		}
	}
	return res;
}

/**
 * Recebe uma string e conta quantas ocorrencias do caractere especificado acontecem na string.
 */
int count_char (char * str, char c, int i) {
	int res = 0;
	
	if (str[i] != '\0') {
		if (str[i] == c) res++;
		return res + count_char(str, c, i+1);
	}

	return res;
}

/**
 * Recebe uma string e retorna a quantidade de vogais que ela tem.
 */
int is_only_vowels(char * str, int i) {
	int res = 0;
	int n_vowels = 0;
	char * vowels = "aeiouAEIOU";
	int len = 0;

	if (vowels[i] != '\0') {
		get_len(str, &len);
		n_vowels = count_char(str, vowels[i], 0);

		if (n_vowels < len) return n_vowels + is_only_vowels(str, i+1);
		else return n_vowels;
	}
}

/**
 * O mesmo que is_only_vowels, mas para consoantes.
 */
int is_only_consonants(char * str, int i) {
	int res = 0;
	int n_consonants = 0;
	char * consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	int len = 0;

	if (consonants[i] != '\0') {
		get_len(str, &len);
		n_consonants = count_char(str, consonants[i], 0);

		if (n_consonants < len) return n_consonants + is_only_consonants(str, i+1);
		else return n_consonants;
	}
}

/**
 * O mesmo que is_only_vowels, mas para numeros.
 */
int is_int(char * str, int i) {
	int res = 0;
	int n_ints = 0;
	char * ints = "1234567890";
	int len = 0;

	if (ints[i] != '\0') {
		get_len(str, &len);
		n_ints = count_char(str, ints[i], 0);

		if (n_ints < len) return n_ints + is_int(str, i+1);
		else return n_ints;
	}
}

/**
 * O mesmo que is_int, mas permitindo ',' e '.'
 */
int is_real(char * str, int i) {
	int res = 0;
	int n_nums = 0;
	char * nums = "1234567890.,";
	int len = 0;

	if (nums[i] != '\0') {
		get_len(str, &len);
		n_nums = count_char(str, nums[i], 0);

		if (n_nums < len) return n_nums + is_real(str, i+1);
		else return n_nums;
	}
}

/**
 * Retorna 1 caso a string tenha apenas um '.' ou ',', e 0 senao
 */
int count_dots(char * str) {
	int res = 1;
	int count = 0;
	
	count = count_char(str, '.', 0);
	if (count <= 1) count += count_char(str, ',', 0);
	if (count > 1) res--;

	return res;
}


int main () {
	char str [1000];
	int len = 0;

	scanf("%[^\n]", str); getchar();
	while (compare(str, "FIM") != 0) {
		get_len(str, &len);

		if (is_only_vowels(str, 0) == len) printf("SIM ");
		else printf("NAO ");
		
		if (is_only_consonants(str, 0) == len) printf("SIM ");
		else printf("NAO ");

		if (is_int(str, 0) == len) printf("SIM ");
		else printf("NAO ");	

		if (is_real(str, 0) == len && count_dots(str) == 1) printf("SIM\n"); // aqui, o valor para ser real deve ter um ',' ou '.' e apenas numeros
		else printf("NAO\n");
		
		scanf("%[^\n]", str); getchar();
		len = 0;
	}

	return 0;
}
