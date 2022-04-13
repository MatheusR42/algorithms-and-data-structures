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

void bubble_sort(int *v, int n)
{
    int changed = 1;
    for (int i = 0; i < n - 1 && changed; i++)
    {
        changed = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                changed = 1;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    bubble_sort(v, n);
    imprimir(v, n);

    return 0;
}