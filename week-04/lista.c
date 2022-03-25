#include <stdio.h>
#include <stdlib.h>
// #include "lista.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

void contar(LinkedNode *inicio, int *qtd, int *soma)
{
    *qtd = 0;
    *soma = 0;
    LinkedNode *atual = inicio;
    while (atual != NULL)
    {
        *qtd = *qtd + 1;
        *soma += atual->data;
        atual = atual->next;
    }
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

void imprimir2(LinkedNode *inicio)
{
    int elements[100];
    int qtd = 0;
    LinkedNode *atual = inicio;
    while (atual != NULL)
    {
        elements[qtd] = atual->data;
        qtd++;
        atual = atual->next;
    }

    for (int i = qtd - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d\n", elements[i]);
        }
        else
        {
            printf("%d ", elements[i]);
        }
    }
}