#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// Função auxiliar para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

// ==========================================
// FUNÇÕES DE TRAVESSIA (PERCURSO)
// ==========================================

// Pré-ordem: Raiz -> Esquerda -> Direita
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Em-ordem (In-ordem): Esquerda -> Raiz -> Direita (Exibe em ordem crescente)
void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        inOrdem(raiz->dir);
    }
}

// Pós-ordem: Esquerda -> Direita -> Raiz (Útil para deletar a árvore)
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

// ==========================================
// FUNÇÕES DE REMOÇÃO
// ==========================================

// Função auxiliar para encontrar o menor valor de uma subárvore
No* encontrarMinimo(No* raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

// Função principal de remoção
No* removerNo(No* raiz, int chave) {
    // Caso base: árvore vazia ou valor não encontrado
    if (raiz == NULL) return raiz;

    // Navega pela árvore para encontrar o nó a ser removido
    if (chave < raiz->valor) {
        raiz->esq = removerNo(raiz->esq, chave);
    } else if (chave > raiz->valor) {
        raiz->dir = removerNo(raiz->dir, chave);
    } else {
        // Nó encontrado! Avaliando os 3 casos de remoção:

        // Caso 1 e 2: Nó com um filho ou nenhum (folha)
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 3: Nó com dois filhos
        // Pega o sucessor in-ordem (menor valor da subárvore direita)
        No* temp = encontrarMinimo(raiz->dir);

        // Copia o valor do sucessor para o nó atual
        raiz->valor = temp->valor;

        // Remove o sucessor da subárvore direita
        raiz->dir = removerNo(raiz->dir, temp->valor);
    }
    return raiz;
}

// ==========================================
// UTILIDADE GERAL
// ==========================================

// Libera toda a memória da árvore (usa lógica de pós-ordem)
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}