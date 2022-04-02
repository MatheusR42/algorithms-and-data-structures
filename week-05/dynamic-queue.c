#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

typedef struct FilaDinamica FilaDinamica;
struct FilaDinamica
{
    LinkedNode *inicio, *fim;
};

FilaDinamica *criar_fila()
{
    FilaDinamica *fila = malloc(sizeof(FilaDinamica));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int enqueue(FilaDinamica *fila, int item)
{
    LinkedNode *node = malloc(sizeof(LinkedNode));
    if (node == NULL)
    {
        return 0;
    }
    node->data = item;
    node->next = NULL;
    if (fila->inicio == NULL)
    {
        fila->inicio = node;
    }
    else
    {
        fila->fim->next = node;
    }
    fila->fim = node;
    return 1;
}

int dequeue(FilaDinamica *fila, int *item)
{
    if (fila->inicio == NULL)
    {
        return 0;
    }
    LinkedNode *node = fila->inicio;
    fila->inicio = node->next;
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }
    *item = node->data;
    free(node);
    return 1;
}

void liberar_fila(FilaDinamica *fila)
{
    LinkedNode *node = fila->inicio;
    while (node != NULL)
    {
        LinkedNode *next = node->next;
        free(node);
        node = next;
    }
    free(fila);
}

int main()
{
    FilaDinamica *f = criar_fila();
    int r, item;

    item = 1;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 2;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 3;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 4;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 5;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    for (int i = 0; i < 6; i++)
    {
        item = -1;
        r = dequeue(f, &item);
        printf("dequeue(%d): %d\n", item, r);
    }

    liberar_fila(f);

    return 0;
}