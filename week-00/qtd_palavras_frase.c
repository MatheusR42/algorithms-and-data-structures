#include <stdio.h>
// #include "qtd_palavras_frase.h"

void imprimir_qtd_palavras(char texto[])
{
    int aux = 0;
    int qtd = 0;
    int lastIsSpace = 0;
    int firstSentence = 1;

    while (1)
    {
        if (texto[aux] == 0)
        {
            qtd++;
            break;
        }

        if (texto[aux] == ' ' && lastIsSpace == 0)
        {
            lastIsSpace = 1;
            qtd++;
        }
        else
        {
            lastIsSpace = 0;
        }

        if (texto[aux] == '.')
        {
            if (lastIsSpace == 1)
            {
                printf("%d\n", qtd - 1);
            }
            else if (firstSentence == 1)
            {
                firstSentence = 0;
                printf("%d\n", qtd + 1);
            }
            else
            {
                printf("%d\n", qtd);
            }

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