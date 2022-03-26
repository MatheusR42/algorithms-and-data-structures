#include <stdlib.h>
#include <stdlib.h>
// #include "intercalar.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

LinkedNode *sortLinkedList(LinkedNode *inicio)
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

LinkedNode *intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2)
{
    LinkedNode *atual1 = inicio1;
    LinkedNode *atual2 = inicio2;
    LinkedNode *anterior = NULL;
    LinkedNode *proximo = NULL;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->data < atual2->data)
        {
            proximo = atual1->next;
            atual1->next = anterior;
            anterior = atual1;
            atual1 = proximo;
        }
        else
        {
            proximo = atual2->next;
            atual2->next = anterior;
            anterior = atual2;
            atual2 = proximo;
        }
    }

    if (atual1 == NULL)
    {
        atual1 = atual2;
    }

    while (atual1 != NULL)
    {
        proximo = atual1->next;
        atual1->next = anterior;
        anterior = atual1;
        atual1 = proximo;
    }

    return sortLinkedList(anterior);
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
    n2.data = 3;
    n1.next = &n2;

    LinkedNode n3;
    n3.data = 7;
    n2.next = &n3;
    n3.next = NULL;

    LinkedNode d1;
    d1.data = 0;

    LinkedNode d2;
    d2.data = 2;
    d1.next = &d2;

    LinkedNode d3;
    d3.data = 9;
    d2.next = &d3;
    d3.next = NULL;

    LinkedNode *n = intercalar_listas(&n1, &d1);
    imprimir1(n);

    return 0;
}