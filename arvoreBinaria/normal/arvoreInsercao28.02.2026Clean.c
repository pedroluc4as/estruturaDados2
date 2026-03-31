#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

typedef struct No
{
    int valor;
    struct No *esq;
    struct No *dir;
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
    novoNo->esq = NULL;
    novoNo->dir = NULL;
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
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void posOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);

        free(raiz);
    }
}

void emOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);

        free(raiz);
    }
}

void preOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);

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