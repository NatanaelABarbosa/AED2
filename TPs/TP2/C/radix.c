#include "models.h"

int main () {
	Veiculo ** veiculos = malloc(MAX*sizeof(Veiculo*));
	Veiculo ** arr      = malloc(MAX*sizeof(Veiculo*));
	int i = 0, x = 0;
	char res[MAX] = "";

	veiculos = lerCsv("veiculos.csv");
	scanf("%d", &x);

	for (i = 0; x != -1; i++) 
	{ arr[i] = searchVeiculoById(x, veiculos); scanf("%d", &x); }

	Veiculo ** new_arr = malloc(i*sizeof(Veiculo*));
	int tmp[10];
	int n = 1;
	int y = 0;

	for (int k = 0; k < 4; k++) {
		for (int j = 0;   j < 10; tmp[j] = 0, j++);
		for (int j = 0;   j < i ; tmp[(arr[j]->ano/n)%10]++, j++);
		for (int j = 1;   j < 10; tmp[j]+=tmp[j-1], j++);
		for (int j = i-1; j >= 0; new_arr[--tmp[(arr[j]->ano/n)%10]] = arr[j], j--);
		for (int j = 0; j < i; arr[j] = new_arr[j], j++);
		n*=10;
	}
	
	for (int j = 0; j < i; j++) {
		formatVeiculo(new_arr[j], res);
		printf("%s\n", res);
	}
	
	for (int j = 0; j < 500; freeVeiculo(veiculos[j]), j++);
	veiculos = arr = new_arr = NULL;
}

