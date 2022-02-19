#include <stdio.h>

int main()
{
    // int qtd;
    // scanf("%d", &qtd);
    // int v[qtd];
    // for (int i = 0; i < qtd; i++)
    // {
    //     int n;
    //     scanf("%d", &n);
    //     v[i] = n;
    // }

    // int qtd = 9;
    // int v[9] = {10, 20, 30, 1, 2, 3, 4, 11, 22};
    int qtd = 23;
    int v[23] = {22, 99, 11, 50, 33, 34, 35, 40, 1, 2, 3, 4, 2, 80, 90, 10, 20, 30, 40, 50, 11, 22, 33};
    // 11 10 9 8 7 6 5 4 3 2 1 10

    int greaterSeqIndex = 0;
    int greaterSeqSize = 0;

    int currentSeqSize = 1;
    int currentSeqIndex = 0;

    int lastItem = v[0];
    for (int i = 1; i < qtd; i++)
    {
        if (v[i] > lastItem)
        {
            lastItem = v[i];
            currentSeqSize++;
        }
        else
        {
            lastItem = v[i];
            if (currentSeqSize > greaterSeqSize)
            {
                greaterSeqSize = currentSeqSize;
                greaterSeqIndex = currentSeqIndex;
            }
            currentSeqIndex = i;
            currentSeqSize = 1;
        }
    }

    if (currentSeqSize > greaterSeqSize)
    {
        greaterSeqSize = currentSeqSize;
        greaterSeqIndex = currentSeqIndex;
    }

    printf("%d\n", greaterSeqIndex);
    printf("%d\n", greaterSeqSize);

    for (int i = 0; i < greaterSeqSize; i++)
    {
        printf("%d ", v[i + greaterSeqIndex]);
        // if (i != )
        // {
        //     printf(" ");
        // }
    }
}