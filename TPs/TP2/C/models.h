#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// DEFINICOES
#define MAX 5000

typedef struct {
	int ano;
	int mes;
	int dia;
} Data;

typedef struct {
	int id;
	char marca[MAX];
	char modelo[MAX];
	int ano;
	char categoria[MAX];
	char combustivel[10][MAX];
	int n_combustivel;
	int cilindros;
	double cilindrada;
	char transmissao[MAX];
	char tracao[MAX];
	double consumoCidade;
	double consumoEstrada;
	double co2;
	bool turbo;
	Data * dataRegistro;
} Veiculo;

// CONSTRUTORES/DELETORES

Veiculo * newVeiculo() {
	Veiculo * tmp = NULL;
	
	tmp = (Veiculo*)malloc(sizeof(Veiculo));
	tmp->dataRegistro = (Data*)malloc(sizeof(Data));

	return tmp;
}


void freeVeiculo(Veiculo * tmp) {
	free(tmp->dataRegistro);
	free(tmp);
}

// FUNCOES 

int get_len(char * str) {
	int res = 0;

	while (str[res] != '\0') res++;

	return res;
}

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

Data * parseData(char * str) {
	Data * tmp = (Data*)malloc(sizeof(Data));

	sscanf(str, "%d-%d-%d", &tmp->ano, &tmp->mes, &tmp->dia);

	return tmp;
}

Veiculo * parseVeiculo(char * str) {
	Veiculo * tmp = newVeiculo();
	char del[] = ",";
	char * token = strtok(str, del);
	int cont = 0;
	char combustiveis[MAX] = "";

	while (token != NULL) {
		switch (cont) {
			case 0:
				sscanf(token, "%d", &tmp->id);	break;
			case 1:
				sscanf(token, " %[^\n]", tmp->marca); break;
			case 2:
				sscanf(token, " %[^\n]", tmp->modelo); break;
			case 3:
				sscanf(token, "%d", &tmp->ano); break;	
			case 4:
				sscanf(token, " %[^\n]", tmp->categoria); break;	
			case 5:
				sscanf(token, " %[^\n]", combustiveis); break;
			case 6: 
				sscanf(token, "%d", &tmp->cilindros); break;	
			case 7: 
				sscanf(token, "%lf", &tmp->cilindrada); break;
			case 8: 
				sscanf(token, " %[^\n]", tmp->transmissao); break;	
			case 9: 
				sscanf(token, " %[^\n]", tmp->tracao); break;		
			case 10: 
				sscanf(token, "%lf", &tmp->consumoCidade); break;	
			case 11: 
				sscanf(token, "%lf", &tmp->consumoEstrada); break;
			case 12: 
				sscanf(token, "%lf", &tmp->co2); break;		
			case 13: 
				char aux[10] = "";
				sscanf(token, " %[^\n]", aux); 
				
				if (compare(aux, "true") == 0) tmp->turbo = true;
				else tmp->turbo = false;

				break;
			case 14: 
				tmp->dataRegistro = parseData(token); break;	
		}
		cont++;
		token = strtok(NULL, del);
	}

	token = strtok(combustiveis, ";");
	tmp->n_combustivel = 0;

	while (token != NULL) {
		sscanf(token, " %[^\n]", tmp->combustivel[tmp->n_combustivel++]);
		token = strtok(NULL, ";");
	}

	return tmp;
}

void formatData(Data * d, char * res) {
	sprintf(res, "%02d/%02d/%d", d->dia, d->mes, d->ano);
}	

void formatVeiculo(Veiculo * v, char * res) {
	char strData[MAX] = "";
	char strTurbo[10] = "";
	char strCombustivel[MAX] = "";

	formatData(v->dataRegistro, strData);
	
	if(v->turbo) sscanf("true", "%s", strTurbo);
	else sscanf("false", "%s", strTurbo);
	
	int cont = 0;
	for (int i = 0; i < v->n_combustivel; i++) {
		for (int j = 0; v->combustivel[i][j] != '\0'; j++) 
			strCombustivel[cont++] = v->combustivel[i][j];
		
		if (i != v->n_combustivel - 1) {
			strCombustivel[cont++] = ',';
		}
	}	
	strCombustivel[cont] = '\0';

	sprintf(res, "[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1lf ## %s ## %s ## %.2lf ## %.2lf ## %.1lf ## %s ## %s]", 
			v->id, v->marca, v->modelo, v->ano, v->categoria, strCombustivel, v->cilindros, v->cilindrada, 
			v->transmissao, v->tracao, v->consumoCidade, v->consumoEstrada, v->co2, strTurbo, strData);
}

Veiculo ** lerCsv(char * path) {
	Veiculo ** veiculos = (Veiculo**)malloc(500 * sizeof(veiculos));
	FILE * file = fopen(path, "r");
	char str[MAX] = "";
	
	fscanf(file, " %[^\n]", str);
	fscanf(file, " %[^\n]", str);
	int i = 0;
	while (!feof(file)) {
		veiculos[i++] = parseVeiculo(str);	
		fscanf(file, " %[^\n]", str);
	}
	
	fclose(file);
	return veiculos;
}

Veiculo * searchVeiculoById(int id, Veiculo ** veiculos) {
	Veiculo * tmp = NULL;
	
	for (int i = 0; i < 500; i++) {
		if (veiculos[i]->id == id) tmp = veiculos[i];
	}

	return tmp;
}

