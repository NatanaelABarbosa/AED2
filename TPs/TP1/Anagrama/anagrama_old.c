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

void to_lower(char * str) {
	int len = get_len(str);
	for (int i = 0; i < len; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') str[i]+=('a'-'A');
	}
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
			for (int j = i+1; j < len; j++) {
				if (str[i] == str[j]) { 
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

/**
 * Recebe duas strings e verifica quantos caracteres da segunda string contem na primeira
 * 
 * @param str1 A string que sera comparada
 * @param str2 A string que tera os caracteres para comparar
 * @return a quantidade de caracteres contidos
 */
int contains_any_char(char * str1, char * str2) {
	int res = 0;
	char cleaned_str [100] = "";
		
	if (str1 != NULL && str2 != NULL) {
		clean(str2, cleaned_str);
		int len_s2 = get_len(cleaned_str);	
		for (int i = 0; i < len_s2; i++) {	
			int len_s1 = get_len(str1); 		
			for (int j = 0; j < len_s1; j++) {
				if (str1[j] == cleaned_str[i]) res++;
				if (res == len_s1) { j = len_s1; i = len_s2;}
			}
		}			
	}
	return res;
}

int is_anagram(char * str1, char * str2) {
	int res = 0;
	int n = 0;

	if (get_len(str1) == get_len(str2)) {
		to_lower(str1); to_lower(str2);	
		n = contains_any_char(str1, str2);
		if (n == get_len(str1)) res++;		
	}
	
	return res;
}

int main () {
	char str1[100] = "";
	char str2[100] = "";
	char tmp[100] = "";
	int n = 0;
	
	scanf("%s %s", str1, str2);	
	while (compare(str1, "FIM")){
		n = is_anagram(str1, str2);
		if (n == 1) printf("SIM\n");
		else printf("NAO\n");
		
		scanf("%s %s", str1, str2);
	};

	return 0;
}

