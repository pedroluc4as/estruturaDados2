#include <stdio.h>
#include <stdlib.h>

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
