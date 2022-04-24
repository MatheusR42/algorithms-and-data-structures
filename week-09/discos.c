#include <stdio.h>
// #include "discos.h"

typedef struct Disco Disco;
struct Disco
{
    int codigo;
    double preco;
};

void imprimir(Disco *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("{cod: %d, price: %lf} ", v[i].codigo, v[i].preco);
    }
    printf("\n");
}

int particiona(Disco *v, int esq, int dir, int tipo, int *comparacoes)
{
    Disco pivo = v[dir];
    int ultimo_menores = esq - 1;

    for (int i = esq; i < dir; i++)
    {
        int shouldSwitch = 0;

        *comparacoes = *comparacoes + 1;
        switch (tipo)
        {
        case 1:
            if (v[i].codigo < pivo.codigo)
            {
                shouldSwitch = 1;
            }
            break;
        case 2:
            if (v[i].codigo > pivo.codigo)
            {
                shouldSwitch = 1;
            }
            break;
        case 3:
            if (v[i].preco < pivo.preco)
            {
                shouldSwitch = 1;
            }
            else if (v[i].preco == pivo.preco && v[i].codigo < pivo.codigo)
            {
                shouldSwitch = 1;
            }
            break;
        default:
            break;
        }

        if (shouldSwitch == 1)
        {
            ultimo_menores++;
            Disco aux = v[ultimo_menores];
            v[ultimo_menores] = v[i];
            v[i] = aux;
        }
    }

    ultimo_menores++;
    v[dir] = v[ultimo_menores];
    v[ultimo_menores] = pivo;

    return ultimo_menores;
}

void _quickSort(Disco *v, int esq, int dir, int tipo, int *comparacoes)
{
    if (esq < dir)
    {
        int pivo = particiona(v, esq, dir, tipo, comparacoes);
        _quickSort(v, esq, pivo - 1, tipo, comparacoes);
        _quickSort(v, pivo + 1, dir, tipo, comparacoes);
    }
}

// tipo=1 : ordem crescente por código
// tipo=2 : ordem decrescente por código
// tipo=3 : ordem crescente por preço e, em caso de empate no preço, ordem crescente por código
int quicksort(Disco *v, int n, int tipo)
{
    int comparacoes = 0;
    _quickSort(v, 0, n - 1, tipo, &comparacoes);
    return comparacoes;
}

int main()
{

    int n = 4;
    Disco v[4] = {
        {2, 20},
        {0, 20},
        {1, 10},
        {3, 30}};

    imprimir(v, n);
    quicksort(v, n, 3);
    imprimir(v, n);

    return 0;
}