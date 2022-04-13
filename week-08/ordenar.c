#include "ordenar.h"
#include "funcao_comparar.h"

void ordenar_vetor(ItemVetor v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (comparar(v[j], v[min]) < 0)
            {
                min = j;
            }
        }
        if (min != i)
        {
            ItemVetor aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}