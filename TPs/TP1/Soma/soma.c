/**
 * @author Natanael Barbosa
 */
#include <stdio.h>

/**
 * Retorna a soma dos digitos de um numero especificado somando o resto da divisao por 10 do numero e dividindo-o por 1.
 */
int digits_sum(int num) {
	int res = 0;

	while (num != 0){
		res += num % 10;
		num/=10; 
	}
	return res;
}

int main () {
	int num = 0;
	int soma = 0;
	
	while (scanf("%d", &num) == 1) {
		soma = digits_sum(num);
		printf("%d\n", soma);
	}

	return 0;
}

