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

void counting_sort(int *v, int n, int k)
{
    int c[k + 1];
    for (int i = 0; i <= k; i++)
    {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        c[v[i]]++;
    }

    for (int i = 0; i <= k; i++)
    {
        c[i] += c[i - 1];
    }

    int result[n];
    int current;
    for (int i = n - 1; i >= 0; i--)
    {
        current = v[i];
        result[c[current] - 1] = current;
        c[current]--;
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = result[i];
    }
}

int main()
{
    srand(time(NULL));

    int n = 10;
    int *v = vetor_aleatorio(n);

    imprimir(v, n);
    counting_sort(v, n, 100);
    imprimir(v, n);
    free(v);

    return 0;
}