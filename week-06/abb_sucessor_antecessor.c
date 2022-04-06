#include <stdlib.h>
#include <stdio.h>
// #include "abb_sucessor_antecessor.h"

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

int get_tree_size(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return 1 + get_tree_size(raiz->esq) + get_tree_size(raiz->dir);
}

void get_tree_as_array(NoArvore *raiz, int *array, int *index)
{
    if (raiz == NULL)
    {
        return;
    }

    get_tree_as_array(raiz->esq, array, index);
    array[*index] = raiz->chave;
    *index = *index + 1;
    get_tree_as_array(raiz->dir, array, index);
}

int sucessor(NoArvore *raiz, int chave)
{
    int size = get_tree_size(raiz);
    int *array = malloc(sizeof(int) * size);
    int index = 0;
    get_tree_as_array(raiz, array, &index);

    int foundIndex = 0;
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        foundIndex++;

        if (array[i] == chave)
        {
            found = 1;
            break;
        }
    }

    if (found == 0 || foundIndex == size)
    {
        free(array);
        return -1;
    }

    int result = array[foundIndex];
    free(array);

    return result;
}

int antecessor(NoArvore *raiz, int chave)
{
    int size = get_tree_size(raiz);
    int *array = malloc(sizeof(int) * size);
    int index = 0;
    get_tree_as_array(raiz, array, &index);

    int foundIndex = size - 1;
    int found = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (array[i] < chave)
        {
            found = 1;
            break;
        }
        foundIndex--;
    }

    if (found == 0 || foundIndex == -1)
    {
        free(array);
        return -1;
    }

    int result = array[foundIndex];
    free(array);

    return result;
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

    printf("%d ", sucessor(tree, 5));
    printf("\n--------------\n");
    printf("%d ", antecessor(tree, 0));

    return 0;
}