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

int main () {
	Veiculo ** veiculos = malloc(MAX*sizeof(Veiculo*));
	Veiculo ** arr      = malloc(MAX*sizeof(Veiculo*));
	int i = 0, x = 0;
	char res[MAX] = "";

	veiculos = lerCsv("veiculos.csv");
	scanf("%d", &x);

	for (i = 0; x != -1; i++) {
		arr[i] = searchVeiculoById(x, veiculos);
		scanf("%d", &x);
	}

	selection(arr, i);

	for (int j = 0; j < i; j++) {
		formatVeiculo(arr[j], res);
		printf("%s\n", res);
	}

	for (int j = 0; j < 500; freeVeiculo(veiculos[j++]));
	arr = veiculos = NULL;
}

