#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No *criarNo(int valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        printf("Fechando o programa...\n");
        return NULL;
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void preOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);

        free(raiz);
    }
}

int main()
{
    No *raiz = criarNo(50);
    raiz->esquerda = criarNo(28);
    raiz->direita = criarNo(80);
    raiz->esquerda->esquerda = criarNo(12);
    raiz->direita->direita = criarNo(96);
    raiz->esquerda->direita = criarNo(39);
    raiz->direita->direita->direita = criarNo(100);

    printf("Valores em pre ordem: ");
    preOrdem(raiz);
    printf("\n");

    return 0;
}