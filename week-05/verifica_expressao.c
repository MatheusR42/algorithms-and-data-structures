#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    char data;
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

int push(PilhaDinamica *pilha, char data)
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

int pop(PilhaDinamica *pilha, char *item)
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

int enqueue(FilaDinamica *fila, char item)
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

int dequeue(FilaDinamica *fila, char *item)
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

void print_fila(FilaDinamica *fila)
{
    LinkedNode *node = fila->inicio;
    while (node != NULL)
    {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

void print_pilha(PilhaDinamica *pilha)
{
    LinkedNode *node = pilha->topo;
    while (node != NULL)
    {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

int verificar_lista(const char *str)
{
    PilhaDinamica *p = criar_pilha();

    int strSize = 0;
    char aux;

    while (1)
    {
        if (str[strSize] == 0)
        {
            break;
        }

        if (str[strSize] == '(')
        {
            push(p, str[strSize]);
        }
        else if (str[strSize] == ')')
        {
            if (pop(p, &aux) == 0 || aux != '(')
            {
                return 0;
            }
        }

        if (str[strSize] == '[')
        {
            push(p, str[strSize]);
        }
        else if (str[strSize] == ']')
        {
            int r = pop(p, &aux);
            if (r == 0 || aux != '[')
            {
                return 0;
            }
        }

        if (str[strSize] == '{')
        {
            push(p, str[strSize]);
        }
        else if (str[strSize] == '}')
        {
            if (pop(p, &aux) == 0 || aux != '{')
            {
                return 0;
            }
        }

        strSize++;
    }

    liberar_pilha(p);

    return 1;
}

int main()
{
    char texto[] = "(10+60-[40+x]-{80})";

    printf(verificar_lista(texto) == 0 ? "NAO" : "SIM");
    return 0;
}