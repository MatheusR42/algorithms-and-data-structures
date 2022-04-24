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

// 0 < 5 < 6 < 4 < 8 < 9 < 7 < 3 < 1 < 2
int getBase10FromBaseMarcian(int n)
{
    switch (n)
    {
    case 0:
        return 0;
    case 5:
        return 1;
    case 6:
        return 2;
    case 4:
        return 3;
    case 8:
        return 4;
    case 9:
        return 5;
    case 7:
        return 6;
    case 3:
        return 7;
    case 1:
        return 8;
    case 2:
        return 9;
    }
}

int convertToBase10(int marcianNumber)
{
    int base10Number = 0;
    int multiplicator = 1;

    while (marcianNumber > 0)
    {
        int lastDigit = marcianNumber % 10;
        base10Number += getBase10FromBaseMarcian(lastDigit) * multiplicator;
        marcianNumber /= 10;
        multiplicator *= 10;
    }
    return base10Number;
}

int particiona(int *v, int esq, int dir, int *comparacoes)
{
    int pivo = v[dir];
    int ultimo_menores = esq - 1;

    for (int i = esq; i < dir; i++)
    {
        *comparacoes = *comparacoes + 1;
        if (convertToBase10(v[i]) < convertToBase10(pivo))
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

void _quickSort(int *v, int esq, int dir, int *comparacoes)
{
    if (esq < dir)
    {
        int pivo = particiona(v, esq, dir, comparacoes);
        _quickSort(v, esq, pivo - 1, comparacoes);
        _quickSort(v, pivo + 1, dir, comparacoes);
    }
}

int quicksortm(int *v, int n)
{
    int comparacoes = 0;
    _quickSort(v, 0, n - 1, &comparacoes);
    return comparacoes;
}

int main()
{
    srand(time(NULL));

    int n = 14;
    int v[14] = {0, 2, 5, 8, 23, 28, 97, 98, 100, 101, 108, 911, 934, 958};

    imprimir(v, n);
    quicksortm(v, n);
    imprimir(v, n);

    return 0;
}