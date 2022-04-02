#include <stdio.h>
#include <stdlib.h>
// #include "inverter.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

LinkedNode *reverse(LinkedNode *inicio)
{
    LinkedNode *atual = inicio;
    LinkedNode *anterior = NULL;
    LinkedNode *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

void imprimir1(LinkedNode *inicio)
{
    LinkedNode *atual = inicio;
    while (atual != NULL)
    {
        if (atual->next == NULL)
        {
            printf("%d\n", atual->data);
        }
        else
        {
            printf("%d ", atual->data);
        }
        atual = atual->next;
    }
}

int main()
{
    LinkedNode n1;
    n1.data = 1;

    LinkedNode n2;
    n2.data = 2;
    n1.next = &n2;

    LinkedNode n3;
    n3.data = 3;
    n2.next = &n3;
    n3.next = NULL;

    LinkedNode *n = reverse(&n1);
    imprimir1(n);

    return 0;
}