#include <stdio.h>
// #include "freq_str.h"

void frequencia_string(const char *str, const char *texto, int *qtd)
{
    int textIndex = 0;
    int strIndex = 0;
    int strSize = 0;
    int aux = 0;

    while (1)
    {
        if (str[strSize] == 0)
        {
            break;
        }

        strSize++;
    }

    int qtdy = 0;
    while (1)
    {
        if (texto[textIndex] == 0)
        {
            if (strIndex == strSize)
            {
                qtdy++;
            }

            break;
        }

        printf("%d --- %c == %c", qtdy, texto[textIndex], str[strIndex]);

        if (str[strIndex] == 0)
        {
            if (strIndex == strSize)
            {
                qtdy++;
            }
            strIndex = 0;
            continue;
        }

        if (texto[textIndex] == str[strIndex] ||
            texto[textIndex] + 32 == str[strIndex] ||
            texto[textIndex] == str[strIndex] + 32)
        {
            printf(" ---- equal\n");
            textIndex++;
            strIndex++;
            continue;
        }

        if (strIndex == strSize)
        {
            qtdy++;
        }

        printf(" ---- diff\n");

        strIndex = 0;

        textIndex++;
    }

    *qtd = qtdy;
}

int main()
{
    char str[] = "ABCA";
    char texto[] = "abcdeABCaBcAbcAbCABcabCaBCde";
    int qtd;
    frequencia_string(str, texto, &qtd);
    // const char *str, const char *texto,

    printf("%d \n", qtd);
}
