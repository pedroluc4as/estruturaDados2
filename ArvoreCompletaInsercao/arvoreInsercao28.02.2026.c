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
        return NULL;
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// A OPERAÇÃO DE INSERÇÃO AUTOMÁTICA
No *inserir(No *raiz, int valor)
{
    // 1. Se a árvore (ou subárvore) for vazia, cria o nó aqui
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    // 2. Se for menor, joga para a esquerda
    if (valor < raiz->valor)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // 3. Se for maior, joga para a direita
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }

    // 4. Retorna a raiz atualizada
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

        free(raiz); // Cuidado: usar free aqui destrói a árvore ao imprimir
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
    No *raiz = NULL; // Começa vazia

    // Agora você não precisa saber a posição. A função decide:
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