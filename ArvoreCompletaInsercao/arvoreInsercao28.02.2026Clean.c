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
        printf("Erro de memoria!\n");
        printf("Fechando o programa...\n");

        return NULL;
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    if (valor < raiz->valor)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void posOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);

        free(raiz);
    }
}

void emOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);

        free(raiz);
    }
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
    No *raiz = NULL;

    raiz = inserir(raiz, 50);
    inserir(raiz, 28);
    inserir(raiz, 80);
    inserir(raiz, 12);
    inserir(raiz, 96);
    inserir(raiz, 39);
    inserir(raiz, 100);

    printf("Arvore montada automaticamente: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}