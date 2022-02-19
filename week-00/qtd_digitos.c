#include "qtd_digitos.h"

int quantidade_digitos(int numero)
{
    int qtd = 0;

    while (numero > 0)
    {
        int digit = numero % 10;
        qtd++;
        numero = numero / 10;
    }

    return qtd;
}