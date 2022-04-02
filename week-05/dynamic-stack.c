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

int main()
{
    PilhaDinamica *p = criar_pilha();
    int r, item;

    item = 1;
    r = push(p, item);
    printf("push(%d) = %d\n", item, r);

    item = 2;
    r = push(p, item);
    printf("push(%d) = %d\n", item, r);

    item = 3;
    r = push(p, item);
    printf("push(%d) = %d\n", item, r);

    item = 4;
    r = push(p, item);
    printf("push(%d) = %d\n", item, r);

    item = 5;
    r = push(p, item);
    printf("push(%d) = %d\n", item, r);

    for (int i = 0; i < 6; i++)
    {
        item = -1;
        r = pop(p, &item);
        printf("pop(%d) = %d\n", item, r);
    }

    liberar_pilha(p);
    return 0;
}