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

int particiona(int *v, int esq, int dir)
{
    int pivo = v[dir];
    int ultimo_menores = esq - 1;

    for (int i = esq; i < dir; i++)
    {
        if (v[i] < pivo)
        {
            ultimo_menores++;
            int aux = v[ultimo_menores];
            v[ultimo_menores] = v[i];
            v[i] = aux;
        }
    }

    ultimo_menores++;
    v[dir] = v[ultimo_menores];
    v[ultimo_menores] = pivo;

    return ultimo_menores;
}

void _quickSort(int *v, int esq, int dir)
{
    if (esq < dir)
    {
        int pivo = particiona(v, esq, dir);
        _quickSort(v, esq, pivo - 1);
        _quickSort(v, pivo + 1, dir);
    }
}

void quickSort(int *v, int n)
{
    _quickSort(v, 0, n - 1);
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    quickSort(v, n);
    imprimir(v, n);
    free(v);

    return 0;
}