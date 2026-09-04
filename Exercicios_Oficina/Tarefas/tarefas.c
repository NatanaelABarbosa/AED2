#include <stdio.h>
#include <stdlib.h>
    
# define MAX_EMERGENCIA 5
# define MAX_PERIODICA 6
# define MAX_BACKGROUND 30

typedef struct {
    int id ;
    int prioridade ; // 0 -10 (0 = maxima prioridade )
}Tarefa;

typedef struct {
    Tarefa pilha [ MAX_EMERGENCIA ] ; // pilha de tarefas
    int n ; // numero de tarefas na lista
} PilhaEmergencia ;

typedef struct {
    Tarefa fila [ MAX_PERIODICA ] ; // fila de tarefas
    int primeiro ; // posicao do primeiro
    int ultimo ; // posicao do ultimo
} FilaPeriodica ;

typedef struct {
    Tarefa lista [ MAX_BACKGROUND ] ; // lista de tarefas
    int n ; // numero de tarefas na lista
} ListaBackground ;

/*
Tarefa * newTarefa(int id, int prioridade) {
    Tarefa * t = NULL;
    if (id > 0 && 0 <= prioridade && prioridade <= 10) {
        t->id = id;
        t->prioridade = prioridade;
    }
    return t;
}
*/

void empilharEmergencia(Tarefa t, PilhaEmergencia * p) {
    if (p->n < MAX_EMERGENCIA) {
        p->pilha[p->n] = t;
        p->n++;
    }
}

Tarefa desempilharEmergencia(PilhaEmergencia * p) {
    Tarefa t;
    t.id = -1;
    t.prioridade = -1;
    
    if (p->n > 0) {
        p->n--;
        t = p->pilha[p->n];
    }

    return t;
}

void mostrarEmergencia(PilhaEmergencia * p) {
    if (p->n > 0) {
        for (int i = 0; i < p->n; i++) {
            printf("t%d: %d|%d\n", i+1, p->pilha[i].id, p->pilha[i].prioridade);
        }
    } else printf("\nPilha Vazia\n");
}

void enfileirarPeriodica(Tarefa t, FilaPeriodica * f) {
    if ((f->ultimo+1) % MAX_PERIODICA != f->primeiro) {
        f->fila[f->ultimo] = t;
        f->ultimo = (f->ultimo + 1) % MAX_PERIODICA;
    }
}

Tarefa desenfileirarPeriodica(FilaPeriodica * f) {
    Tarefa t;
    t.id = -1;
    t.prioridade = -1;

    if (f->ultimo != f->primeiro) {
        t = f->fila[f->primeiro];
        f->primeiro = (f->primeiro + 1) % MAX_PERIODICA;
    }
    
    return t;
}

void mostrarPeriodica(FilaPeriodica * f) {
    if (f-> ultimo != f->primeiro) {
        int j = 0;
        for (int i = f->primeiro; i != f->ultimo; i = (i+1) % MAX_PERIODICA) {
            printf("t%d: %d|%d\n", ++j, f->fila[i].id, f->fila[i].prioridade);
        }
    } else printf("\nFila Vazia\n");
}

void inserirBackground(Tarefa t);

Tarefa removerBackground();

Tarefa processarTarefa (PilhaEmergencia * p, FilaPeriodica * f, ListaBackground * l);
void promoverTarefa (PilhaEmergencia * p, ListaBackground * l, int id) ;
void imprimirEstruturas (PilhaEmergencia * p , FilaPeriodica * f, ListaBackground * l);

int main (void) {
    PilhaEmergencia * p = malloc(sizeof(PilhaEmergencia));
    FilaPeriodica * f = malloc(sizeof(FilaPeriodica));
    int opcao = 0;
    Tarefa t;
    int n = 0;
    
    do {
        printf("\n0. Sair\n");
        printf("1. Adicionar pilha\n");
        printf("2. Remover pilha\n");
        printf("3. Adicionar fila\n");
        printf("4. Remover fila\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("id: ");
                scanf("%d", &n); 
                t.id = n;
                
                printf("prioridade (0 a 10): ");
                scanf("%d", &n);
                t.prioridade = n;

                printf("\n");
                empilharEmergencia(t, p);
                mostrarEmergencia(p);
                
                printf("\n");
            break;
            case 2:
                t = desempilharEmergencia(p);
                if (t.prioridade != -1) printf("removido: %d (id), %d (prioridade)\n", t.id, t.prioridade);
                else printf("nenhuma tarefa removida\n");
                
                mostrarEmergencia(p);
            break;
            case 3:
                printf("id: ");
                scanf("%d", &n); 
                t.id = n;
                
                printf("prioridade (0 a 10): ");
                scanf("%d", &n);
                t.prioridade = n;

                printf("\n");
                enfileirarPeriodica(t, f);
                mostrarPeriodica(f);
                
                printf("\n");
            break;
            case 4:
                t = desenfileirarPeriodica(f);
                if (t.prioridade != -1) printf("removido: %d (id), %d (prioridade)\n\n", t.id, t.prioridade);
                else printf("nenhuma tarefa removida\n");
                
                mostrarPeriodica(f);
            break;
            default: break;
        }
        printf("\nAPERTE ENTER PARA CONTINUAR\n"); getchar(); getchar();
        
    } while (opcao != 0);

    free(p);
    return 0;
}
