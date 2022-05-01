#include "heapsort.h"
#include "funcao_comparar.h"

void max_heapfy(ItemVetor *v, int n, int i, int *qtd)
{
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior = i;

    if (esq < n)
    {
        *qtd = *qtd + 1;
        if (comparar(v[esq], v[maior]) > 0)
            maior = esq;
    }

    if (dir < n)
    {
        *qtd = *qtd + 1;
        if (comparar(v[dir], v[maior]) > 0)
        {
            maior = dir;
        }
    }

    if (maior != i)
    {
        ItemVetor aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;

        max_heapfy(v, n, maior, qtd);
    }
}

void build_max_heap(ItemVetor *v, int n, int *qtd)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapfy(v, n, i, qtd);
}

int heapsort(ItemVetor *v, int n)
{
    int qtd = 0;

    build_max_heap(v, n, &qtd);

    for (int i = n - 1; i >= 0; i--)
    {
        ItemVetor aux = v[0];
        v[0] = v[i];
        v[i] = aux;

        max_heapfy(v, i, 0, &qtd);
    }

    return qtd;
}
