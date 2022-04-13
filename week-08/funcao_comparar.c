#include "ordenar.h"
#include "funcao_comparar.h"

typedef struct ItemVetor ItemVetor;
struct ItemVetor
{
    char *modelo;
    char *planeta;
    int autonomia;
};

// source: https://stackoverflow.com/questions/22973670/creating-my-own-strcmp-function-in-c
int my_strcmp(const char *a, const char *b)
{
    while (*a && *a == *b)
    {
        ++a;
        ++b;
    }
    return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}

int comparar(ItemVetor item1, ItemVetor item2)
{
    if (item1.autonomia < item2.autonomia)
    {
        return -1;
    }

    if (item1.autonomia > item2.autonomia)
    {
        return 1;
    }

    if (my_strcmp(item1.planeta, item2.planeta) < 0)
    {
        return -1;
    }

    if (my_strcmp(item1.planeta, item2.planeta) > 0)
    {
        return 1;
    }

    if (my_strcmp(item1.modelo, item2.modelo) < 0)
    {
        return -1;
    }

    if (my_strcmp(item1.modelo, item2.modelo) > 0)
    {
        return 1;
    }

    return 0;
}