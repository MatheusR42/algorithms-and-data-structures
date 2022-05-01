#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode
{
    char *data; // ponteiro para um vetor de char com uma string
    LinkedNode *next;
};

void imprimir(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

// fonte do comparador: https://pt.stackoverflow.com/questions/293113/comparar-um-vetor-do-tipo-char
int compara_strings(char str1[], char str2[])
{
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        // assim que uma letra seja diferente
        if (str1[i] != str2[i])
        {
            // retorna -1 se a primeira for menor ou 1 caso contrário
            return str1[i] < str2[i] ? -1 : 1;
        }
    }
    // Se as duas acabaram, são iguais e retorna 0. Se a str1 acabou e str2 não
    // retorna um valor negativo. Se str2 acabou e a str1 retorna um valor positivo
    return str1[i] - str2[i];
}

void intercala(char *v, int esq_inicio, int esq_fim, int dir_fim, int *comparacoes)
{
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio;
    int dir = dir_inicio;

    int size = dir_fim - esq_inicio + 1;
    int *aux = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        if (esq > esq_fim)
        {
            aux[i] = v[dir++];
            continue;
        }

        if (dir > dir_fim)
        {
            aux[i] = v[esq++];
            continue;
        }

        *comparacoes = *comparacoes + 1;
        if (compara_strings(v[esq], v[dir]) <= 0)
        {
            aux[i] = v[esq++];
            continue;
        }

        aux[i] = v[dir++];
    }

    for (int i = 0; i < size; i++)
    {
        v[esq_inicio + i] = aux[i];
    }

    free(aux);
}

void _mergeSort(char *v, int esq, int dir, int *comparacoes)
{
    if (esq < dir)
    {
        int meio = (esq + dir) / 2;
        _mergeSort(v, esq, meio, comparacoes);
        _mergeSort(v, meio + 1, dir, comparacoes);
        intercala(v, esq, meio, dir, comparacoes);
    }
}

void mergeSort(char *v, int size, int *comparacoes)
{
    _mergeSort(v, 0, size - 1, comparacoes);
}

LinkedNode *mergesort(LinkedNode *inicio, int *comparacoes)
{
    LinkedNode *aux = inicio;
    int size = 0;
    while (aux != NULL)
    {
        size++;
        aux = aux->next;
    }

    int *v = malloc(sizeof(char) * size);
    int i = 0;
    aux = inicio;
    while (aux != NULL)
    {
        v[i] = aux->data;
        aux = aux->next;
        i++;
    }

    mergeSort(v, size, comparacoes);
}

int main()
{
    LinkedNode *n1 = malloc(sizeof(LinkedNode));
    char d_nome1[] = "Disciplina15";
    n1->data = &d_nome1;
    LinkedNode *n2 = malloc(sizeof(LinkedNode));
    char d_nome2[] = "Disciplina16";
    n2->data = &d_nome2;

    n1->next = n2;
    n2->next = NULL;

    int *comparacoes = malloc(sizeof(int));
    *comparacoes = 0;
    mergesort(n1, comparacoes);
    printf("Comparacoes: %d\n", *comparacoes);

    free(comparacoes);
    return 0;
}