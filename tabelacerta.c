#include <stdlib.h>
#include <stdio.h>

//Lucas deodato

typedef struct {
    int vetor[10];
    int chave;
} hash;

hash* criar() {
    hash* h = (hash*)malloc(sizeof(hash));
    for (int i = 0; i < 10; i++) {
        h->vetor[i] = -1;
    }
    h->chave = -1;
    return h;
}

int hashing(int chave) {
    return chave % 10;
}

void inserir(hash* h, int chave) {
    if(h->chave == 10) {
        printf("                            tabela cheia\n");
        return;
    }
    int indice = hashing(chave);
    while (h->vetor[indice] != -1) {
        indice = (indice + 1) % 10;
    }
    h->vetor[indice] = chave;
    h->chave++;
}

int buscar(hash* h, int chave) {
    int indice = hashing(chave);
    int tent = 0;
    while (h->vetor[indice] != 0 && tent < 10) {
        if (h->vetor[indice] == chave) {
            return 1;
        }
        indice = (indice + 1) % 10;
        tent++;
    }
    return 0;
}


void imprimir(hash* h) {
    for (int i = 0; i < 10; i++) {
        if( h->vetor[i] == -1){
            printf("\n                            Vazio!");
        }else{
            printf("\n                            %d", h->vetor[i]);
        }
    }
}

int main() {
    hash* h = criar();
    int v, op, busca;
    do {
        printf("\n                            ---------------------------------\n                            TABELA HASH\n                            ---------------------------------\n                            1-Inserir\n                            2-Buscar\n                            3-Imprimir\n                            4-Sair\n");
        printf("                            Escolha:");
        scanf("%d", &op);
        printf("\n                            --------------------------------\n");
        switch (op) {
            case 1:
                printf("                            Digite o valor a ser inserido: ");
                scanf("%d", &v);
                inserir(h, v);
                break;
            case 2:
                printf("                            Digite o valor a ser buscado: ");
                scanf("%d", &busca);
                if (buscar(h, busca)) {
                    printf("                            Valor %d encontrado na tabela.\n", busca);
                } else {
                    printf("                            Valor %d nao encontrado na tabela.\n", busca);
                }
                break;
            case 3:
                imprimir(h);
                break;
            case 4:
                free(h);
                return 0;
            default:
                printf("                            Opcao invalida.\n");
                break;
        }
    } while (op != 4);
}
