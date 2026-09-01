#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int * arr;
	int n;
	int cap;
} Pilha;

Pilha * newPilha(int cap) {
	Pilha * p = NULL;

	if (cap > 0) {
		p = malloc(sizeof(Pilha));
		p->arr = malloc(cap*sizeof(int));
		p->n = 0;
		p->cap = cap;
	}
	return p;	
}

void delPilha(Pilha* p) { 
	free(p->arr);
	free(p);
} 

void empilhar(Pilha* p, int x) { 
	if (p->n < p->cap) {
		p->arr[p->n] = x;
		p->n++;
	}
}

int desempilhar(Pilha* p) { 
	int res = -1;
	
	if (p->n >= 0) {
		return p->arr[--p->n];
	}	

	return res;
} 


void mostrar(Pilha* p) { 
	for (int i = p->n-1; i >=0; i--) {
		printf("%d ", p->arr[i]);
	}

	printf("\n");
} 

bool pesquisar(Pilha* p, int x) {
	bool res = false;
	for (int i = 0; i < p->n; i++) {
		if (p->arr[i] == x) {res = true; i = p->n;}
	} 
	return res;
}

void main () {
	Pilha * p = NULL;
	char comando = '0';
	int n = 0;

	while (scanf("%c", &comando) == 1) {
		if (comando == 'C') {
			scanf("%d", &n);
			p = newPilha(n);
		} else if (comando == 'E') {
			scanf("%d", &n);
			empilhar(p, n);
		} else if (comando == 'P') {
			scanf("%d", &n);
			if (pesquisar(p, n)) printf("%c\n", 'S');
			else printf("%c\n", 'N'); 
		} else if (comando == 'D') printf("%d\n", desempilhar(p));
		else if (comando == 'M') mostrar(p);
		
	}

}

