#include <stdlib.h>
#include "abb_menor_chave.h"

NoArvore *buscaNo(NoArvore *raiz, int key)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (key == raiz->chave)
    {
        return raiz;
    }
    else if (key < raiz->chave)
    {
        return buscaNo(raiz->esq, key);
    }
    else
    {
        return buscaNo(raiz->dir, key);
    }
}

int get_min(NoArvore *raiz)
{
    if (raiz->esq == NULL)
    {
        return raiz->chave;
    }
    else
    {
        return get_min(raiz->esq);
    }
}

NoArvore *remover(NoArvore *raiz, int chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (chave < raiz->chave)
    {
        raiz->esq = remover(raiz->esq, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->dir = remover(raiz->dir, chave);
    }
    else
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            return NULL;
        }

        if (raiz->esq == NULL)
        {
            NoArvore *arvDir = raiz->dir;
            return arvDir;
        }

        if (raiz->dir == NULL)
        {
            NoArvore *arvEsq = raiz->esq;
            return arvEsq;
        }

        int sucessor = get_min(raiz->dir);
        raiz->chave = sucessor;
        raiz->dir = remover(raiz->dir, sucessor);
    }

    return raiz;
}

int menor_chave_comum(NoArvore *raiz1, NoArvore *raiz2)
{
    if (raiz1 == NULL || raiz2 == NULL)
    {
        return -1;
    }

    int min1 = get_min(raiz1);
    NoArvore *no = buscaNo(raiz2, min1);
    if (no == NULL)
    {
        return menor_chave_comum(remover(raiz1, min1), raiz2);
    }

    return min1;
}