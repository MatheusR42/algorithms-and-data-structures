#include <stdlib.h>
#include <stdio.h>

typedef struct PilhaEstatica PilhaEstatica;
struct PilhaEstatica
{
    int *items;
    int tamanho, topo;
};

PilhaEstatica *criar_pilha(int tamanho)
{
    PilhaEstatica *p = malloc(sizeof(PilhaEstatica));
    p->items = malloc(sizeof(int) * tamanho);
    p->tamanho = tamanho;
    p->topo = -1;
    return p;
}

int push(PilhaEstatica *p, int item)
{
    if (p->topo == p->tamanho - 1)
    {
        return 0;
    }
    p->topo++;
    p->items[p->topo] = item;
    return 1;
}

int pop(PilhaEstatica *p, int *item)
{
    if (p->topo == -1)
    {
        return 0;
    }
    *item = p->items[p->topo];
    p->topo--;
    return 1;
}

void liberar_pilha(PilhaEstatica *p)
{
    free(p->items);
    free(p);
}

int main()
{
    PilhaEstatica *p = criar_pilha(4);
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

    for (int i = 0; i < 5; i++)
    {
        item = -1;
        r = pop(p, &item);
        printf("pop(%d) = %d\n", item, r);
    }

    liberar_pilha(p);

    return 0;
}