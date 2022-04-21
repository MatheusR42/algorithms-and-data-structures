// #include "insertionsort.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode
{
    int data;
    DLinkedNode *prev, *next;
};

DLinkedNode *insertion_sort(DLinkedNode *inicio, int *comparacoes)
{
    DLinkedNode *current, *aux;
    *comparacoes = 0;

    if (inicio == NULL || inicio->next == NULL)
    {
        return inicio;
    }

    current = inicio->next;
    while (current != NULL)
    {
        int currentData = current->data;
        DLinkedNode *aux = current->prev;

        while (aux != NULL)
        {
            *comparacoes = *comparacoes + 1;
            if (currentData < aux->data)
            {
                int temp = aux->data;
                aux->data = currentData;
                aux->next->data = temp;
            }
            aux = aux->prev;
        }
        current = current->next;
    }

    return inicio;
}

void imprimir2(DLinkedNode *inicio)
{
    DLinkedNode *atual = inicio;
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

// 5
// 11 22 33 44 55

// -- Expected output (exact text)---
// next:
// 11 22 33 44 55
// prev:
// 55 44 33 22 11
// Comparacoes: 4

// --- Input ---
// 8
// 66 33 22 55 88 11 44 77
// --- Expected output (exact text)---
// next:
// 11 22 33 44 55 66 77 88
// prev:
// 88 77 66 55 44 33 22 11
// Comparacoes: 17
void test02()
{
    DLinkedNode n1;
    n1.data = 4;
    n1.prev = NULL;

    DLinkedNode n2;
    n2.data = 3;
    n2.prev = &n1;
    n1.next = &n2;

    DLinkedNode n3;
    n3.data = 2;
    n3.prev = &n2;
    n2.next = &n3;

    DLinkedNode n4;
    n4.data = 1;
    n4.prev = &n3;
    n4.next = NULL;
    n3.next = &n4;
    int qtd;

    imprimir2(&n1);
    insertion_sort(&n1, &qtd);
    imprimir2(&n1);
    printf("-----%d---", qtd);
}

int main()
{
    test02();
    return 0;
}
