#include <stdlib.h>
#include <stdio.h>

typedef struct NoArvore NoArvore;
struct NoArvore
{
    int chave;
    struct NoArvore *esq;
    struct NoArvore *dir;
};

NoArvore *inserir(NoArvore *raiz, int chave_nova)
{
    if (raiz == NULL)
    {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    if (chave_nova < raiz->chave)
    {
        raiz->esq = inserir(raiz->esq, chave_nova);
    }
    else if (chave_nova > raiz->chave)
    {
        raiz->dir = inserir(raiz->dir, chave_nova);
    }

    return raiz;
}

void imprimir(NoArvore *raiz, int profundidade)
{
    if (raiz == NULL)
    {
        return;
    }

    imprimir(raiz->dir, profundidade + 1);
    for (int i = 0; i < profundidade; i++)
    {
        printf("   ");
    }
    printf("%d\n", raiz->chave);
    imprimir(raiz->esq, profundidade + 1);
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

void percurso_emordem(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    percurso_emordem(raiz->esq);
    printf("%d ", raiz->chave);
    percurso_emordem(raiz->dir);
}

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
            free(raiz);
            return NULL;
        }

        if (raiz->esq == NULL)
        {
            NoArvore *arvDir = raiz->dir;
            free(raiz);
            return arvDir;
        }

        if (raiz->dir == NULL)
        {
            NoArvore *arvEsq = raiz->esq;
            free(raiz);
            return arvEsq;
        }

        int sucessor = get_min(raiz->dir);
        raiz->chave = sucessor;
        raiz->dir = remover(raiz->dir, sucessor);
    }

    return raiz;
}

int main()
{
    NoArvore *tree = NULL;
    tree = inserir(tree, 5);
    tree = inserir(tree, 1);
    tree = inserir(tree, 8);
    tree = inserir(tree, 10);
    tree = inserir(tree, 6);
    tree = inserir(tree, 3);
    tree = inserir(tree, 0);

    imprimir(tree, 0);
    printf("\n--------------\n");
    percurso_emordem(tree);
    printf("\n--------------\n");
    printf("%d ", numero_nos(tree));
    printf("\n--------------\n");
    printf("%d ", numero_nos_folha(tree));
    printf("\n--------------\n");
    printf("%d ", numero_nos_internos(tree));
    printf("\n--------------\n");

    tree = remover(tree, 5);
    imprimir(tree, 0);

    return 0;
}