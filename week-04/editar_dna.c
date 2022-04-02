#include <stdio.h>
#include <stdlib.h>
// #include "editar_dna.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    char data;
    LinkedNode *next;
};

void convertSeq(LinkedNode *seq_edicao)
{
    LinkedNode *atual = seq_edicao;
    while (atual != NULL)
    {
        switch (atual->data)
        {
        case 'A':
            atual->data = 'T';
            break;
        case 'T':
            atual->data = 'A';
            break;
        case 'C':
            atual->data = 'G';
            break;
        case 'G':
            atual->data = 'C';
            break;
        default:
            break;
        }
        atual = atual->next;
    }
}

int isAMatch(LinkedNode *inicio, LinkedNode *seq_edicao)
{
    LinkedNode *atual1 = inicio;
    LinkedNode *atual2 = seq_edicao;

    while (atual2 != NULL)
    {
        if (atual1 == NULL || atual1->data != atual2->data)
        {
            return 0;
        }

        atual1 = atual1->next;
        atual2 = atual2->next;
    }

    return 1;
}

void removeFirstOcurrence(LinkedNode *inicio, char val)
{
    LinkedNode *atual = inicio;
    LinkedNode *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->data == val)
        {
            if (anterior == NULL)
            {
                inicio = atual->next;
            }
            else
            {
                anterior->next = atual->next;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
}

void removeSeq(LinkedNode *anterior, LinkedNode *inicio, LinkedNode *seq_edicao)
{
    LinkedNode *atual = seq_edicao;
    LinkedNode *finalPointer = inicio;
    while (atual != NULL)
    {
        // LinkedNode *temp = finalPointer->next;
        // free(finalPointer);
        // finalPointer = temp;
        // atual = atual->next;

        atual = atual->next;
        finalPointer = finalPointer->next;
    }

    if (finalPointer == NULL)
    {
        anterior->next = NULL;
    }
    else
    {
        inicio->data = finalPointer->data;
        inicio->next = finalPointer->next;
    }
}

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao)
{
    convertSeq(seq_edicao);

    LinkedNode *inicio = dna_original;
    LinkedNode *atual = inicio;
    LinkedNode *anterior = NULL;
    while (atual != NULL)
    {
        if (isAMatch(atual, seq_edicao))
        {
            removeSeq(anterior, atual, seq_edicao);
        }
        anterior = atual;
        atual = atual->next;
    }

    return inicio;
}

void imprimir(LinkedNode *inicio)
{
    LinkedNode *atual = inicio;
    while (atual != NULL)
    {
        if (atual->next == NULL)
        {
            printf("%c\n", atual->data);
        }
        else
        {
            printf("%c ", atual->data);
        }
        atual = atual->next;
    }
}

int main()
{
    LinkedNode *n1 = malloc(sizeof(LinkedNode));
    n1->data = 'A';
    LinkedNode *n2 = malloc(sizeof(LinkedNode));
    n2->data = 'C';
    LinkedNode *n3 = malloc(sizeof(LinkedNode));
    n3->data = 'G';
    LinkedNode *n4 = malloc(sizeof(LinkedNode));
    n4->data = 'T';
    LinkedNode *n5 = malloc(sizeof(LinkedNode));
    n5->data = 'A';
    LinkedNode *n6 = malloc(sizeof(LinkedNode));
    n6->data = 'G';
    LinkedNode *n7 = malloc(sizeof(LinkedNode));
    n7->data = 'A';
    LinkedNode *n8 = malloc(sizeof(LinkedNode));
    n8->data = 'C';
    LinkedNode *n9 = malloc(sizeof(LinkedNode));
    n9->data = 'G';
    LinkedNode *n10 = malloc(sizeof(LinkedNode));
    n10->data = 'T';
    LinkedNode *n11 = malloc(sizeof(LinkedNode));
    n11->data = 'T';
    LinkedNode *n12 = malloc(sizeof(LinkedNode));
    n12->data = 'C';
    LinkedNode *n13 = malloc(sizeof(LinkedNode));
    n13->data = 'T';
    LinkedNode *n14 = malloc(sizeof(LinkedNode));
    n14->data = 'A';

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = n11;
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = NULL;

    LinkedNode d1;
    d1.data = 'G';
    LinkedNode d2;
    d2.data = 'C';
    LinkedNode d3;
    d3.data = 'A';

    d1.next = &d2;
    d2.next = &d3;
    d3.next = NULL;

    imprimir(n1);
    LinkedNode *res = editar_dna(n1, &d1);
    imprimir(res);

    return 0;
}