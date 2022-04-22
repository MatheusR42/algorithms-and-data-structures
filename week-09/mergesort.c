#include <stdlib.h>
#include <stdio.h>

void imprimir(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim, int *comparacoes)
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

        *comparacoes = *comparacoes + 1;
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

void _mergeSort(int *v, int esq, int dir, int *comparacoes)
{
    if (esq < dir)
    {
        int meio = (esq + dir) / 2;
        _mergeSort(v, esq, meio, comparacoes);
        _mergeSort(v, meio + 1, dir, comparacoes);
        intercala(v, esq, meio, dir, comparacoes);
    }
}

void mergeSort(int *v, int size, int *comparacoes)
{
    _mergeSort(v, 0, size - 1, comparacoes);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int elem;
        scanf("%d", &elem);
        v[i] = elem;
    }

    int *comparacoes = malloc(sizeof(int));
    *comparacoes = 0;
    mergeSort(v, n, comparacoes);
    imprimir(v, n);
    printf("Comparacoes: %d\n", *comparacoes);

    free(v);
    free(comparacoes);
    return 0;
}