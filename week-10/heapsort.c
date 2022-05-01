#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *vetor_aleatorio(int n)
{
    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
    }

    return v;
}

void imprimir(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void max_heapfy(int *v, int n, int i)
{
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior = i;

    if (esq < n && v[esq] > v[maior])
        maior = esq;

    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i)
    {
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;

        max_heapfy(v, n, maior);
    }
}

void build_max_heap(int *v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapfy(v, n, i);
}

void heap_sort(int *v, int n)
{
    build_max_heap(v, n);

    for (int i = n - 1; i > 0; i--)
    {
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;

        max_heapfy(v, i, 0);
    }
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    heap_sort(v, n);
    imprimir(v, n);
    free(v);

    return 0;
}