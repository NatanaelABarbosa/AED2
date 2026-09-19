#include "models.h"

int main () {
	Veiculo ** veiculos = malloc(MAX*sizeof(Veiculo*));
	Veiculo ** arr      = malloc(MAX*sizeof(Veiculo*));
	int i = 0, x = 0;
	char res[MAX] = "";

	veiculos = lerCsv("veiculos.csv");
	scanf("%d", &x);

	int maior = 0;	
	for (i = 0; x != -1; i++) {
		arr[i] = searchVeiculoById(x, veiculos);
		if (arr[i]->cilindros > maior) maior = arr[i]->cilindros;
		scanf("%d", &x);
	}
	maior++;

	Veiculo ** new_arr = malloc(i*sizeof(Veiculo*));
	int tmp[maior];

	for (int j = 0;   j < maior; tmp[j] = 0, j++);
	for (int j = 0;   j < i    ; tmp[arr[j]->cilindros]++, j++);
	for (int j = 1;   j < maior; tmp[j]+=tmp[j-1], j++);
	for (int j = i-1; j >= 0   ; new_arr[--tmp[arr[j]->cilindros]] = arr[j], j--);
	
	for (int j = 0; j < i; j++) {
		formatVeiculo(new_arr[j], res);
		printf("%s\n", res);
	}
	
	for (int j = 0; j < 500; freeVeiculo(veiculos[j]), j++);
	veiculos = arr = new_arr = NULL;
}
