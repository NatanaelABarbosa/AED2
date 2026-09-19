#include "models.h"

int main () {
	Veiculo ** veiculos = malloc(MAX*sizeof(Veiculo*));
	veiculos = lerCsv("veiculos.csv");
	char strVeiculo[MAX] = "";
	int n = 0;
	
	scanf("%d", &n);
	while (n != -1) {
		for (int i = 0; i < 500; i++) {
			if (veiculos[i]->id == n) {
				formatVeiculo(veiculos[i], strVeiculo);
				printf("%s\n", strVeiculo);
				i=500;
			}
		}	
		scanf("%d", &n);
	}

	for (int i = 0; i < 500; i++) 
	{ freeVeiculo(veiculos[i]); veiculos[i] = NULL; }

	return 0;
}	

