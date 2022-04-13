#include "selectionsort.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    int data;
    LinkedNode *next;
};

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes)
{
    LinkedNode *aux, *menor, *atual;
    *trocas = 0;
    *comparacoes = 0;
    if (inicio == NULL)
    {
        return NULL;
    }
    atual = inicio;
    while (atual->next != NULL)
    {
        menor = atual;
        aux = atual->next;
        while (aux != NULL)
        {
            *comparacoes += 1;
            if (aux->data < menor->data)
            {
                menor = aux;
            }
            aux = aux->next;
        }
        if (menor != atual)
        {
            int temp = menor->data;
            menor->data = atual->data;
            atual->data = temp;
            *trocas += 1;
        }
        atual = atual->next;
    }
    return inicio;
}