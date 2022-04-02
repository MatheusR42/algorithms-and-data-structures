#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica
{
    LinkedNode *topo;
};

PilhaDinamica *criar_pilha()
{
    PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}

int push(PilhaDinamica *pilha, int data)
{
    LinkedNode *node = malloc(sizeof(LinkedNode));
    if (node == NULL)
    {
        return 0;
    }

    node->data = data;
    node->next = pilha->topo;
    pilha->topo = node;
    return 1;
}

int pop(PilhaDinamica *pilha, int *item)
{
    if (pilha->topo == NULL)
    {
        return 0;
    }
    LinkedNode *node = pilha->topo;
    pilha->topo = node->next;
    *item = node->data;
    free(node);
    return 1;
}

void liberar_pilha(PilhaDinamica *pilha)
{
    LinkedNode *node = pilha->topo;
    while (node != NULL)
    {
        LinkedNode *next = node->next;
        free(node);
        node = next;
    }
    free(pilha);
}

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

int verificar_lista(LinkedNode *lista)
{
    int i = 0;
    LinkedNode *node = lista;
    FilaDinamica *f = criar_fila();
    PilhaDinamica *p = criar_pilha();

    while (node != NULL)
    {
        int r, item;
        item = node->data;

        r = push(p, item);
        printf("push(%d) = %d\n", item, r);

        r = enqueue(f, item);
        printf("enqueue(%d) = %d\n", item, r);
        node = node->next;
        i++;
    }

    int result = 1;

    while (i > 0)
    {
        int r1, r2, item1, item2;
        r1 = pop(p, &item1);
        printf("pop(%d) = %d\n", item1, r1);
        r2 = dequeue(f, &item2);
        printf("dequeue(%d) = %d\n", item2, r2);
        i--;

        if (item1 != item2)
        {
            result = 0;
        }
    }

    liberar_fila(f);
    liberar_pilha(p);

    return result;
}

int main()
{
    LinkedNode *n1 = malloc(sizeof(LinkedNode));
    n1->data = 1;

    LinkedNode *n2 = malloc(sizeof(LinkedNode));
    n2->data = 2;
    n1->next = n2;

    LinkedNode *n3 = malloc(sizeof(LinkedNode));
    n3->data = 3;
    n2->next = n3;

    LinkedNode *n4 = malloc(sizeof(LinkedNode));
    n4->data = 4;
    n3->next = n4;

    LinkedNode *n5 = malloc(sizeof(LinkedNode));
    n5->data = 5;
    n5->next = NULL;

    printf("%d\n", verificar_lista(n1));
    return 0;
}