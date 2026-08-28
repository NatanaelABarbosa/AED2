#include <stdio.h>

/**
* Retorna a posicao do '\0' na string
*/
int get_len(char * str) {
	int res = 0;

	while (str[res] != '\0') res++;

	return res;
}

/**
* Verifica a equidade de duas stings
*
* @return 1 caso diferente, 0 caso iguais
*/
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
* Recebe uma string e remove os espaços no fim dela
*/
void remove_last_spaces (char * str) {
	int len = get_len(str);
	while (str[len-1] == ' ')  str[--len] = '\0';
}

/**
 * Recebe uma string e retorna outra string sem caracteres repetidos
 *
 * @param str A string que sera copiada e modificada
 * @return A string sem caracteres repetidos
 */
void clean(char * str, char * res) {
	int repeated = 0;
	int k = 0;

	if (str != NULL && res != NULL) {
		int len = get_len(str);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < k; j++) {
				if (str[i] == res[j]) { 
					repeated = 1; j=len;
				}
			}

			if (repeated == 0) {	
				res[k] = str[i];
				k++;
			} 
			repeated = 0;
		}
		res[k] = '\0';
	}
}



int main () {
	return 0;
}
