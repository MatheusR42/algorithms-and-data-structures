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

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim)
{
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio;
    int dir = dir_inicio;

    int size = dir_fim - esq_inicio + 1;
    int *aux = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        if (esq > esq_fim)
        {
            aux[i] = v[dir++];
            continue;
        }

        if (dir > dir_fim)
        {
            aux[i] = v[esq++];
            continue;
        }

        if (v[esq] <= v[dir])
        {
            aux[i] = v[esq++];
            continue;
        }

        aux[i] = v[dir++];
    }

    for (int i = 0; i < size; i++)
    {
        v[esq_inicio + i] = aux[i];
    }

    free(aux);
}

void _mergeSort(int *v, int esq, int dir)
{
    if (esq < dir)
    {
        int meio = (esq + dir) / 2;
        _mergeSort(v, esq, meio);
        _mergeSort(v, meio + 1, dir);
        intercala(v, esq, meio, dir);
    }
}

void mergeSort(int *v, int size)
{
    _mergeSort(v, 0, size - 1);
}

int main()
{
    srand(time(NULL));
    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    mergeSort(v, n);
    imprimir(v, n);

    return 0;
}