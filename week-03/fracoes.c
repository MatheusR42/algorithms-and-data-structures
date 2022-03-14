#include "fracoes.h"

int mdc(int n, int m)
{
    int sobra;

    while (n != 0)
    {
        sobra = m % n;
        m = n;
        n = sobra;
    }

    return m;
}

Fracao somar(Fracao f1, Fracao f2)
{
    int n = (f1.numerador * f2.denominador + f2.numerador * f1.denominador);
    int d = f1.denominador * f2.denominador;

    int mdcVal = mdc(n, d);
    n = n / mdcVal;
    d = d / mdcVal;

    Fracao f;
    f.numerador = n;
    f.denominador = d;
    return f;
}

Fracao somar_vetor(Fracao f[], int n_fracoes)
{
    Fracao f2 = f[0];
    int i = 1;

    while (i < n_fracoes)
    {
        f2 = somar(f2, f[i]);
        i++;
    }

    return f2;
}

Fracao multiplicar(Fracao f1, Fracao f2)
{
    int n = f1.numerador * f2.numerador;
    int d = f1.denominador * f2.denominador;

    int mdcVal = mdc(n, d);
    n = n / mdcVal;
    d = d / mdcVal;

    Fracao f;
    f.numerador = n;
    f.denominador = d;
    return f;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes)
{
    Fracao f2 = f[0];
    int i = 1;

    while (i < n_fracoes)
    {
        f2 = multiplicar(f2, f[i]);
        i++;
    }

    return f2;
}