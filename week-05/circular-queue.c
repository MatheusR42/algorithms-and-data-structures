#include <stdlib.h>
#include <stdio.h>

typedef struct FilaCircular FilaCircular;
struct FilaCircular
{
    int *itens;
    int tamanho, inicio, fim;
};

FilaCircular *criar_fila(int tamanho)
{
    FilaCircular *f = malloc(sizeof(FilaCircular));
    f->itens = malloc(sizeof(int) * tamanho);
    f->tamanho = tamanho;
    f->inicio = 0;
    f->fim = 0;
    return f;
}

int enqueue(FilaCircular *f, int item)
{
    int novo_fim = (f->fim + 1) % f->tamanho;
    if (novo_fim == f->inicio)
    {
        return 0;
    }

    f->itens[f->fim] = item;
    f->fim = novo_fim;
    return 1;
}

int dequeue(FilaCircular *f, int *item)
{
    if (f->inicio == f->fim)
    {
        return 0;
    }

    *item = f->itens[f->inicio];

    f->inicio = (f->inicio + 1) % f->tamanho;
    return 1;
}

void liberar_fila(FilaCircular *f)
{
    free(f->itens);
    free(f);
}

int main()
{
    FilaCircular *f = criar_fila(4);
    int r, item;

    item = 1;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 2;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 3;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 4;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    item = 5;
    r = enqueue(f, item);
    printf("enqueue(%d): %d\n", item, r);

    for (int i = 0; i < 4; i++)
    {
        item = -1;
        r = dequeue(f, &item);
        printf("dequeue(%d): %d\n", item, r);
    }

    liberar_fila(f);

    return 0;
}