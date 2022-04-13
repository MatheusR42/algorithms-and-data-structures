#include <stdlib.h>
#include <stdio.h>

typedef struct NoArvore NoArvore;
struct NoArvore
{
    int chave;
    int altura;
    struct NoArvore *esq;
    struct NoArvore *dir;
};

int altura(NoArvore *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return root->altura;
}

int calc_fb(NoArvore *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return altura(root->esq) - altura(root->dir);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

NoArvore *inserir(NoArvore *raiz, int chave_nova)
{
    if (raiz == NULL)
    {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->altura = 0;
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

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
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

void liberar_arvore(NoArvore *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
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

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    return raiz;
}

int main()
{
    NoArvore *tree = NULL;
    tree = inserir(tree, 50);
    tree = inserir(tree, 10);
    tree = inserir(tree, 80);
    tree = inserir(tree, 70);
    tree = inserir(tree, 90);
    tree = inserir(tree, 85);

    imprimir(tree, 0);
    printf("\n--------------\n");

    NoArvore *no = buscaNo(tree, 50);
    int fb = calc_fb(no);
    printf("fb(%d) = %d\n", no->chave, fb);

    return 0;
}