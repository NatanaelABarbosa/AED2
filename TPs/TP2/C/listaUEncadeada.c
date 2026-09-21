#include "models.h"

typedef struct Celula {
	Veiculo       * veiculo;
	struct Celula *    prox;
} Celula;

typedef struct {
	Celula * primeiro;
	Celula *   ultimo;
	int n;
} Lista;

Celula * newCelula() {
	Celula * tmp = malloc(sizeof(Celula));
	tmp->veiculo = NULL;
	tmp->prox    = NULL;
	return tmp;
}

Lista * newLista() {
	Lista * tmp = NULL;
	tmp = malloc(sizeof(Lista));
	
	tmp->primeiro = NULL;
	tmp->ultimo = NULL;
	tmp->n = 0;

	return tmp;
}

void freeLista(Lista * lista) {	
	if (lista->primeiro != NULL) free(lista->primeiro);
	if (lista->ultimo   != NULL) free(lista->ultimo  );
	free(lista);
}

void mostrar(Lista * lista) {
	char s[300] = "";
	int cont = 0;
	for (Celula * i = lista->primeiro; i != NULL; i=i->prox) {
		formatVeiculo(i->veiculo, s);
		printf("%s\n", s);
	}
}

void inserirInicio(Veiculo * v, Lista * lista) {
	Celula * tmp = newCelula();
	tmp->veiculo = v;

	if (lista->primeiro == NULL) { lista->primeiro = tmp; lista->ultimo = tmp; }
	else {
		tmp->prox = lista->primeiro;
		lista->primeiro = tmp;
	} 
	lista->n++;
}

void inserirFim(Veiculo * v, Lista * lista) {
	Celula * tmp = newCelula();
	tmp->veiculo = v;

	if (lista->primeiro == NULL) { lista->primeiro = tmp; lista->ultimo = tmp; }
	else {
		lista->ultimo->prox = tmp;
		lista->ultimo = tmp;
	}	
	lista->n++;
}

void inserir(Veiculo * v, Lista * lista, int pos) {
	Celula * tmp = NULL;
	Celula * new = newCelula();
	new->veiculo = v;

	if (pos >= 0 && pos <= lista->n) {
		if (pos == 0) inserirInicio(v, lista);
		else if (pos == lista->n) inserirFim(v, lista);
		else {
			tmp = lista->primeiro; 
			for (int i = 0; i < pos-1; tmp = tmp->prox, i++);
			new->prox = tmp->prox;
			tmp->prox = new;
		}
		lista->n++;
	}
}

Veiculo * removerInicio(Lista * lista) {
	Celula * tmp = NULL;

	if (lista->primeiro != NULL) {
		lista->n--; tmp = lista->primeiro;
		if (lista->primeiro == lista->ultimo) { lista->primeiro = NULL; lista->ultimo = NULL; }
		 else lista->primeiro = lista->primeiro->prox;
	}

	return tmp->veiculo;
}

Veiculo * removerFim(Lista * lista) {
	Celula * tmp = NULL;

	if (lista->primeiro != NULL) {	
		lista->n--; tmp = lista->primeiro;
		if (lista->primeiro == lista->ultimo) {
			tmp = lista->primeiro;
			lista->primeiro = NULL; lista->ultimo = NULL;
		}
		else {
			for (int i = 0; i < lista->n-1; tmp = tmp->prox, i++);
			lista->ultimo = tmp;
			tmp = lista->ultimo->prox;
			lista->ultimo->prox = NULL;
		}
	}

	return tmp->veiculo;
}

Veiculo * remover(Lista * lista, int pos) {
	Celula * tmp = NULL;
	Celula * res = NULL;

	if (pos >= 0 && pos < lista->n) {
		if (pos == 0) removerInicio(lista);
		else if (pos == lista->n-1) removerFim(lista);
		else {
			tmp = lista->primeiro; 
			for (int i = 0; i < pos-1; tmp = tmp->prox, i++);
			res = tmp->prox;
			tmp->prox = tmp->prox->prox;
			lista->n--;
		}
	}

	return res->veiculo;
}

int main () {
	Veiculo ** veiculos = malloc(500*sizeof(Veiculo*));
	Lista * lista = newLista();
	Veiculo * vtmp = NULL;
	char s[200] = "";
	char c[3] = "";
	int n = 0, x = 0, pos = 0, i = 0;
	
	veiculos = lerCsv("veiculos.csv");

	scanf("%d", &x);
	for (i = 0; x != -1; i++) {
		vtmp = searchVeiculoById(x, veiculos);	
		inserirFim(vtmp, lista);
		scanf("%d", &x);
	}

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c%c", &c[0], &c[1]);
		
		if (c[0] == 'I') {
			if (c[1] == '*') {
				scanf("%d %d", &pos, &x);
				vtmp = searchVeiculoById(x, veiculos);	
				inserir(vtmp, lista, pos);
			} else if (c[1] == 'F') {
				scanf("%d", &x);
				vtmp = searchVeiculoById(x, veiculos);	
				inserirFim(vtmp, lista);
			} else {	
				scanf("%d", &x);
				vtmp = searchVeiculoById(x, veiculos);	
				inserirInicio(vtmp, lista);
			}
		} else {
			if (c[1] == '*') {
				scanf("%d", &pos);
				vtmp = remover(lista, pos);
				printf("(R)%s %s\n", vtmp->marca, vtmp->modelo);

			} else if (c[1] == 'F') {	
				vtmp = removerFim(lista);
				printf("(R)%s %s\n", vtmp->marca, vtmp->modelo);
			} else {	
				vtmp = removerInicio(lista);
				printf("(R)%s %s\n", vtmp->marca, vtmp->modelo);
			}
		}
	}

	mostrar(lista);	
	for (i = 0; i < 500; i++) freeVeiculo(veiculos[i]);
	veiculos = NULL;
	vtmp = NULL;
	return 0;
}


