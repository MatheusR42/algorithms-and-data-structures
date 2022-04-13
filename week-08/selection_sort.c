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

void selection_sort(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    selection_sort(v, n);
    imprimir(v, n);

    return 0;
}