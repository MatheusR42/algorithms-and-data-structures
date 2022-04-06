#include <stdlib.h>
#include "qtd_nos.h"

void numero_nos2(NoArvore *raiz, int *num)
{
    if (raiz == NULL)
    {
        return;
    }
    *num = *num + 1;

    numero_nos2(raiz->esq, num);
    numero_nos2(raiz->dir, num);
}

void numero_nos_folha2(NoArvore *raiz, int *num)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        *num = *num + 1;
    }

    numero_nos_folha2(raiz->esq, num);
    numero_nos_folha2(raiz->dir, num);
}

int numero_nos(NoArvore *raiz)
{
    int *num = malloc(sizeof(int));

    numero_nos2(raiz, num);
    int result = *num;
    free(num);

    return result;
}

int numero_nos_folha(NoArvore *raiz)
{
    int *num = malloc(sizeof(int));

    numero_nos_folha2(raiz, num);
    int result = *num;
    free(num);

    return result;
}

int numero_nos_internos(NoArvore *raiz)
{
    return numero_nos(raiz) - numero_nos_folha(raiz);
}
