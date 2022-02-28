#include <stdio.h>
#include <stdlib.h>
// #include "vetor.h"

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido)
{
    int finalSize = 0;

    for (int i = 1; i < n_compactado; i += 2)
    {
        finalSize += vetor[i];
    }

    int *compact = malloc(sizeof(int) * finalSize);

    int currentVal;
    int aux = 0;
    for (int i = 0; i < n_compactado; i++)
    {
        if (i % 2 == 0)
        {
            currentVal = vetor[i];
        }
        else
        {

            for (int j = 0; j < vetor[i]; j++)
            {
                compact[aux] = currentVal;
                aux++;
            }
        }
    }

    *n_expandido = finalSize;
    return compact;
}

int main()
{
    int v[] = {10, 5, 50, 2, 10, 3, 90, 1};
    int p;
    int *result = expandir_vetor(v, 8, &p);

    printf("%d \n", p);

    for (int i = 1; i < p; i++)
    {
        printf("%d  \n", result[i]);
    }

    free(result);
}