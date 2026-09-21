#include "models.h"

typedef struct {
	int primeiro;
	int ultimo;
	Veiculo ** arr;
} Fila;

Fila * newFila(int n) {
	Fila * tmp = NULL;
	tmp = malloc(sizeof(Fila));
	
	tmp->primeiro = tmp->ultimo = 0;
	tmp->arr = malloc(n*sizeof(Veiculo *));
	for (int i = 0; i < n; i++) tmp->arr[i] = NULL;

	return tmp;
}

void freeFila(Fila * fila) {
	free(fila->arr);
	free(fila);
}

Veiculo * desenfileirar (Fila * fila) {
	Veiculo * res = NULL; 
	char tmp[500] = "";

	if (fila->arr[fila->primeiro] != NULL) {
		res = fila->arr[fila->primeiro];
		printf("(R)%s %s\n", res->marca, res->modelo);
		fila->arr[fila->primeiro] = NULL;
	    	if (fila->primeiro != fila->ultimo) fila->primeiro = (fila->primeiro + 1)%5;
	}

	return res;
}

void enfileirar (Veiculo * v, Fila * fila) {
	Veiculo * vtmp = NULL;
	if ((fila->ultimo+1)%5 == fila->primeiro) vtmp = desenfileirar(fila);
	
	if (fila->arr[fila->primeiro] != NULL) fila->ultimo = (fila->ultimo + 1)%5;
	fila->arr[fila->ultimo] = v;
}

void mostrar (Fila * fila) {
	char tmp[200] = "";
	int n = 0, m = 0;
	
	if (fila->arr[fila->primeiro] != NULL) {
		n = fila->primeiro;
		while (n != fila->ultimo) { n = (n + 1)%5; m++; }
		n = fila->primeiro;
		for (int i = 0; i < m+1; i++) {
			formatVeiculo(fila->arr[n], tmp);
			printf("%s\n", tmp);
			n = (n+1)%5;
		}
	} 
}

int main () {
	Veiculo ** veiculos = malloc(500*sizeof(Veiculo*));
	Fila * fila = newFila(5);
	Veiculo * vtmp = NULL;
	char c = '0';
	int n = 0, x = 0, i = 0;
	
	veiculos = lerCsv("veiculos.csv");

	scanf("%d", &x);
	for (i = 0; x != -1; i++) {
		vtmp = searchVeiculoById(x, veiculos);	
		enfileirar(vtmp, fila);
		scanf("%d", &x);
	}

	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		scanf(" %c", &c);

		vtmp = NULL;
		if (c == 'I') {
			scanf("%d", &x); 
			vtmp = searchVeiculoById(x, veiculos);	
				
			if (vtmp != NULL) enfileirar(vtmp, fila);
		} else {		
			vtmp = desenfileirar(fila);
		}
	}

	mostrar(fila);

	for (i = 0; i < 500; i++) freeVeiculo(veiculos[i]);
	veiculos = NULL;
	vtmp = NULL;
}

