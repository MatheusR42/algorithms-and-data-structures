#include <stdlib.h>
#include "abb_menor_maior.h"

typedef struct NoArvore NoArvore;
struct NoArvore
{
    int chave;
    struct NoArvore *esq;
    struct NoArvore *dir;
};

int menor(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->esq == NULL)
    {
        return raiz->chave;
    }
    else
    {
        return menor(raiz->esq);
    }
}

int maior(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (raiz->dir == NULL)
    {
        return raiz->chave;
    }
    else
    {
        return maior(raiz->dir);
    }
}
