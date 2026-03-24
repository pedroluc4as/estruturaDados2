#include <stdio.h>
#include <stdlib.h>
//AQUI ESTARÃO AS FUNÇÕES DA MINHA BST (BINARY SEARCH TREE) ou ABB (ARVORE BINARIA DE BUSCA)

//PRIMEIRA FUNÇÃO
//criar um novo Nó na memória

struct No* criarNo(int valor)
{
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;


    return novoNo;
}