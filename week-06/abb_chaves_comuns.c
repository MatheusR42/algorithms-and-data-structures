#include <stdlib.h>
#include "abb_chaves_comuns.h"

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

void percurso_emordem(NoArvore *raiz1, NoArvore *raiz2, int *sum)
{
    if (raiz1 == NULL)
    {
        return;
    }

    NoArvore *found = buscaNo(raiz2, raiz1->chave);
    if (found != NULL)
    {
        *sum = *sum + 1;
    }

    percurso_emordem(raiz1->esq, raiz2, sum);
    percurso_emordem(raiz1->dir, raiz2, sum);
}

int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2)
{
    if (raiz1 == NULL || raiz2 == NULL)
    {
        return 0;
    }

    int *qtd = malloc(sizeof(int));
    percurso_emordem(raiz1, raiz2, qtd);
    int result = *qtd;
    free(qtd);

    return result;
}