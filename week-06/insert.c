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
    return 0;
}