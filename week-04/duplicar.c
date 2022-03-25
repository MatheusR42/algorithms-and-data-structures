#include <stdio.h>
#include <stdlib.h>
// #include "duplicar.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode
{
    int data;
    DLinkedNode *next, *prev;
};

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

void duplicar_pares1(LinkedNode *inicio)
{
    LinkedNode *atual = inicio;
    LinkedNode *anterior = NULL;
    LinkedNode *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->next;
        if (atual->data % 2 == 0)
        {
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            novo->data = atual->data;
            novo->next = proximo;
            atual->next = novo;
        }
        anterior = atual;
        atual = proximo;
    }
}

void duplicar_pares2(DLinkedNode *inicio)
{
    DLinkedNode *atual = inicio;
    DLinkedNode *anterior = NULL;
    DLinkedNode *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->next;
        if (atual->data % 2 == 0)
        {
            DLinkedNode *novo = malloc(sizeof(DLinkedNode));
            novo->data = atual->data;
            novo->next = proximo;
            novo->prev = atual;
            atual->next = novo;

            if (proximo != NULL)
            {
                proximo->prev = novo;
            }
        }
        anterior = atual;
        atual = proximo;
    }
}

void test01()
{
    LinkedNode n1;
    n1.data = 1;

    LinkedNode n2;
    n2.data = 2;
    n1.next = &n2;

    LinkedNode n3;
    n3.data = 3;
    n2.next = &n3;

    LinkedNode n4;
    n4.data = 4;
    n3.next = &n4;
    n4.next = NULL;

    LinkedNode *inicio = &n1;

    duplicar_pares1(inicio);
    imprimir1(inicio);
}

void test02()
{
    DLinkedNode n1;
    n1.data = 1;
    n1.prev = NULL;

    DLinkedNode n2;
    n2.data = 2;
    n2.prev = &n1;
    n1.next = &n2;

    DLinkedNode n3;
    n3.data = 3;
    n3.prev = &n2;
    n2.next = &n3;

    DLinkedNode n4;
    n4.data = 4;
    n4.prev = &n3;
    n4.next = NULL;
    n3.next = &n4;

    duplicar_pares2(&n1);
    imprimir2(&n1);
}

int main()
{
    test01();
    test02();
    return 0;
}