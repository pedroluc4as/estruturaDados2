#include "biblioteca.h"

#define PRETO 0
#define VERMELHO 1

typedef struct No {
    int vlr;
    int cor; // Apenas uma variável para definir a cor atual do nó
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(int vlr) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return NULL;
    }
    novoNo->vlr = vlr;
    novoNo->cor = VERMELHO; // Regra 1: Todo nó novo nasce Vermelho
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

void inOrdem(No *raiz) {
    if (raiz != NULL) {
        // 1. Vai para a esq
        inOrdem(raiz->esq);

        // 2. Imprime o vlr e a cor no meio
        if (raiz->cor == PRETO) {
            printf("%d(P) ", raiz->vlr);
        } else {
            printf("%d(V) ", raiz->vlr);
        }

        // 3. Vai para a dir
        inOrdem(raiz->dir);

        // 4. Libera a memória de baixo para cima
        free(raiz);
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        // 1. Vai para o fundo da esq
        posOrdem(raiz->esq);

        // 2. Vai para o fundo da dir
        posOrdem(raiz->dir);

        // 3. Imprime o vlr e a cor no final
        if (raiz->cor == PRETO) {
            printf("%d(P) ", raiz->vlr);
        } else {
            printf("%d(V) ", raiz->vlr);
        }

        // 4. Libera a memória de baixo para cima
        free(raiz);
    }
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        // Imprime o vlr e a cor correspondente (P ou V)
        if (raiz->cor == PRETO) {
            printf("%d(P) ", raiz->vlr);
        } else {
            printf("%d(V) ", raiz->vlr);
        }
        
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);

        free(raiz);
    }
}

int main() {
    No *raiz = criarNo(50);
    raiz->cor = PRETO; // Regra 2: A raiz da árvore é obrigatoriamente Preta

    // Montando a árvore manualmente (nós nascem vermelhos por padrão)
    raiz->esq = criarNo(28);
    raiz->dir = criarNo(80);
    raiz->esq->esq = criarNo(12);
    raiz->dir->dir = criarNo(96);
    raiz->esq->dir = criarNo(39);
    raiz->dir->dir->dir = criarNo(100);

    printf("vlres em Pre-Ordem (com cores): ");
    preOrdem(raiz);
    printf("\n");

    return 0;
}