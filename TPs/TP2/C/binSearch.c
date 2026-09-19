#include "models.h"

int biggerString(char * str1, char * str2) {
	int res = 0;
	int i = 0;
	char tmp[3];
	bool stop = false;

	if (compare(str1, str2) == 0) stop = true;

	while (stop == false) {
		tmp[0] = str1[i];
		tmp[1] = str2[i];

		if ('A' <= tmp[0] && tmp[0] <= 'Z') tmp[0] += 'a' - 'A';
		if ('A' <= tmp[1] && tmp[1] <= 'Z') tmp[1] += 'a' - 'A';

		     if (tmp[0] == '\0' && tmp[1] != '\0') { res--; stop = true; }
		else if (tmp[0] != '\0' && tmp[1] == '\0') { res++; stop = true; }
		else if (tmp[0] == ' ' && tmp[1] != ' ') {res --; stop = true; }
		else if (tmp[0] != ' ' && tmp[1] == ' ') {res ++; stop = true; }
		else if (tmp[0] < tmp[1]) { res--; stop = true; }
		else if (tmp[0] > tmp[1]) { res++; stop = true; }
		else if (tmp[0] == '\0' && tmp[1] == '\0') stop = true;
		i++;
	}

	return res;
}

void selection(Veiculo ** arr, int i) {
	char tmp[3] = "";
	int cur = 0;
	int l = 0;
	int menor = 0;
	Veiculo * vtmp;

	for (int j = 0; j < i-1; j++) {
		menor = j;

		for (int k = j+1; k < i; k++) {	
			if (biggerString(arr[k]->modelo, arr[menor]->modelo) < 0) 
				menor = k;
		}
		vtmp = arr[j];
		arr[j] = arr[menor];
		arr[menor] = vtmp;
	}
	vtmp = NULL;
}

bool searchByModelo (Veiculo ** arr, int i, char * s) {
	bool founded = false;
	int esq = 0;
	int dir = i-1;
	int pivo = 0;
	int a = 0;

	while (esq <= dir) {
		pivo = (dir+esq)/2;	
		a = biggerString(s, arr[pivo]->modelo);
		
		if (a == 0) { dir = esq-1; founded = true; }
		else if (a > 0) esq = pivo+1;
		else dir = pivo-1;
	}		
	return founded;
}

int main () {
	Veiculo ** veiculos = malloc(MAX*sizeof(Veiculo*));
	Veiculo ** arr      = malloc(MAX*sizeof(Veiculo*));
	int i = 0, x = 0;

	veiculos = lerCsv("veiculos.csv");
	scanf("%d", &x);

	for (i = 0; x != -1; i++) {
		arr[i] = searchVeiculoById(x, veiculos);
		scanf("%d", &x);
	}
	
	selection(arr, i);

	char s [100] = "";
	bool founded = false;
	
	scanf(" %[^\r\n]", s);
	while (compare(s, "FIM") != 0) {
		founded = searchByModelo(arr, i, s);
		if (founded) printf("SIM\n");
		else printf("NAO\n");
		scanf(" %[^\r\n]", s);
	}
	
	for (int j = 0; j < 500; freeVeiculo(veiculos[j++]));
	arr = veiculos = NULL;
}


