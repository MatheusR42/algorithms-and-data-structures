#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "abb_string.h"

typedef struct NoArvore NoArvore;
struct NoArvore
{
    char *chave;
    struct NoArvore *esq;
    struct NoArvore *dir;
};

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
    printf("%s\n", raiz->chave);
    imprimir(raiz->esq, profundidade + 1);
}

char *get_min(NoArvore *raiz)
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

NoArvore *buscar(NoArvore *raiz, char *chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (strcmp(chave, raiz->chave) == 0)
    {
        return raiz;
    }
    else if (strcmp(chave, raiz->chave) < 0)
    {
        return buscar(raiz->esq, chave);
    }
    else
    {
        return buscar(raiz->dir, chave);
    }
}

NoArvore *inserir(NoArvore *raiz, char *chave_nova)
{
    if (raiz == NULL)
    {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        char *str = malloc(sizeof(char) * 100);
        strcpy(str, chave_nova);
        novo_no->chave = str;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    if (strcmp(chave_nova, raiz->chave) < 0)
    {
        raiz->esq = inserir(raiz->esq, chave_nova);
    }
    else if (strcmp(chave_nova, raiz->chave) > 0)
    {
        raiz->dir = inserir(raiz->dir, chave_nova);
    }

    return raiz;
}

NoArvore *remover(NoArvore *raiz, char *chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (strcmp(chave, raiz->chave) < 0)
    {
        raiz->esq = remover(raiz->esq, chave);
    }
    else if (strcmp(chave, raiz->chave) > 0)
    {
        raiz->dir = remover(raiz->dir, chave);
    }
    else
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz->chave);
            free(raiz);
            return NULL;
        }

        if (raiz->esq == NULL)
        {
            NoArvore *arvDir = raiz->dir;
            free(raiz->chave);
            free(raiz);
            return arvDir;
        }

        if (raiz->dir == NULL)
        {
            NoArvore *arvEsq = raiz->esq;
            free(raiz->chave);
            free(raiz);
            return arvEsq;
        }

        char *sucessor = get_min(raiz->dir);
        char *str = malloc(sizeof(char) * 100);
        strcpy(str, sucessor);
        raiz->chave = str;
        raiz->dir = remover(raiz->dir, str);
    }

    return raiz;
}

void liberar_arvore(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz->chave);
    free(raiz);
}

int main()
{
    char *str1 = malloc(sizeof(char) * 10);
    char *str2 = malloc(sizeof(char) * 10);
    char *str3 = malloc(sizeof(char) * 10);
    char *str4 = malloc(sizeof(char) * 10);
    int ret;

    strcpy(str1, "dados");
    strcpy(str2, "algoritmos");
    strcpy(str3, "estruturas");
    strcpy(str4, "professor");
    // strcpy(str2, "algoritmos");

    NoArvore *tree = NULL;
    tree = inserir(tree, str1);
    imprimir(tree, 0);
    printf("\n--------------\n");
    tree = inserir(tree, str2);
    imprimir(tree, 0);
    printf("\n--------------\n");
    tree = inserir(tree, str3);
    imprimir(tree, 0);
    printf("\n--------------\n");
    tree = inserir(tree, str4);
    imprimir(tree, 0);
    printf("\n--------------\n");

    remover(tree, str3);
    remover(tree, str2);
    imprimir(tree, 0);
    printf("\n--------------\n");

    NoArvore *r = buscar(tree, str1);
    if (r == NULL)
    {
        printf("NAO ENCONTRADO");
    }
    else
    {
        printf("ENCONTRADO");
    }

    liberar_arvore(tree);
    free(str1);
    free(str2);
    free(str3);
    free(str4);

    return 0;
}