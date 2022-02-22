#include <stdio.h>
// #include "qtd_palavras_frase.h"

int isText(char c)
{
    if (c == ' ' || c == '.' || c == ',')
    {
        return 0;
    }

    return 1;
}

void imprimir_qtd_palavras(char texto[])
{
    int aux = 0;
    int qtd = 0;
    int inText = 0;

    while (1)
    {
        if (texto[aux] == 0)
        {
            qtd++;
            break;
        }

        if (inText == 0 && isText(texto[aux]) == 1)
        {
            inText = 1;
        }

        if (inText == 1 && isText(texto[aux]) == 0)
        {
            inText = 0;
            qtd++;
        }

        if (texto[aux] == '.')
        {
            printf("%d\n", qtd);
            qtd = 0;
        }
        aux++;
    }
}
// Algoritmos   e   Estruturas de Dados I. Nessa disciplina,     serao vistas estruturas de dados como   listas, pilhas, filas e arvores  .   Tambem serao vistos algoritmos de  busca  e  ordenacao.
int main()
{
    char frase[9999];

    fgets(frase, 9999, stdin);
    imprimir_qtd_palavras(frase);
}