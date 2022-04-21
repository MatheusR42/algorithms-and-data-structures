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

void insertion_sort(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = v[i];
        int index = i;
        for (int j = i - 1; j >= 0 && current < v[j]; j--)
        {
            v[j + 1] = v[j];
            index--;
        }

        v[index] = current;
    }
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    insertion_sort(v, n);
    imprimir(v, n);

    return 0;
}