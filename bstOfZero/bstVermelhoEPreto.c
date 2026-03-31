#include "library.h"

typedef struct No
{
    int valor;
    struct No *esq;
    struct No *dir;
    sturct No *cor;
} No;

No* criarNo(int valor)
{
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    
    return novoNo;
}

