#include "valor_freq.h"

int valor_frequente(int v[], int n)
{
    int greater;
    int maxQtd = 0;

    for (int i = 0; i < n; i++)
    {
        int currentQtd = 0;

        for (int j = 0; j < n; j++)
        {
            if (v[j] == v[i])
            {
                currentQtd++;
            }
        }

        if (currentQtd > maxQtd)
        {
            greater = v[i];
            maxQtd = currentQtd;
        }
    }

    return greater;
}