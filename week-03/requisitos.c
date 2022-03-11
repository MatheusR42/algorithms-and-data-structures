#include <stdlib.h>
#include "requisitos.h"

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd)
{
    *qtd = 0;

    if (disciplina->requisito == NULL)
    {
        return disciplina->requisito;
    }

    while (disciplina->requisito != NULL)
    {
        *qtd = *qtd + 1;
        disciplina = disciplina->requisito;
    }

    return disciplina;
}