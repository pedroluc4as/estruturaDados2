#include <stdio.h>
#include <stdlib.h>

//REMOÇÃO DE UM NO COM DOIS FILHOS, E QUE ESSES DOIS FILHOS TENHAM FILHOS

struct No {
    int valor;
    sturct No *esquerda;
    struct No *direita;
} No;