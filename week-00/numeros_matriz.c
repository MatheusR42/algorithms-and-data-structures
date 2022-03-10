#include <stdio.h>
// #include "numeros_matriz.h"

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas])
{
    int celVal = m[l][c];
    m[l][c] = 0;

    // remove top
    if (l > 0 && m[l - 1][c] == celVal)
    {
        // m[l - 1][c] = 0;
        remover_numeros_matriz(l - 1, c, n_linhas, n_colunas, m);
    }

    // remove bottom
    if (l < n_linhas - 1 && m[l + 1][c] == celVal)
    {
        // m[l + 1][c] = 0;
        remover_numeros_matriz(l + 1, c, n_linhas, n_colunas, m);
    }

    // remove right
    if (c < n_colunas - 1 && m[l][c + 1] == celVal)
    {
        // m[l][c + 1] = 0;
        remover_numeros_matriz(l, c + 1, n_linhas, n_colunas, m);
    }

    // remove left
    if (c > 0 && m[l][c - 1] == celVal)
    {
        // m[l][c - 1] = 0;
        remover_numeros_matriz(l, c - 1, n_linhas, n_colunas, m);
    }
}

int main()
{
    int m[5][5] = {
        {11, 22, 33, 22, 55},
        {22, 22, 22, 11, 11},
        {22, 22, 33, 44, 11},
        {11, 22, 22, 22, 22},
        {11, 11, 11, 22, 55},
    };

    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("\n");

    remover_numeros_matriz(2, 0, 5, 5, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

    return 0;
}