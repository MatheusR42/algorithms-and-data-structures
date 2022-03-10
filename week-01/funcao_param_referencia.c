#include "funcao_param_referencia.h"

void funcao(int a, int b, int *resultado)
{
    int result = 0;
    for (int i = 1; i <= a; i++)
    {
        int sum = 0;
        for (int j = 1; j <= b; j++)
        {
            sum += i * j + 10;
        }

        result += 5 * i * sum;
    }

    *resultado = result;
}