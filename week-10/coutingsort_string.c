#include <stdlib.h>
#include <stdio.h>

void imprimir(int *v, int n)
{
    printf("[");

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

    printf("]\n");
}

int char_to_int(char c)
{
    return c - '0' - 16;
}

char int_to_char(int i)
{
    return i + '0' + 16;
}

void counting_sort(int *v, int n, int k)
{
    int c[k + 1];
    for (int i = 0; i < k + 1; i++)
    {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        c[v[i] - 1]++;
    }
    imprimir(c, k);

    for (int i = 1; i < k + 1; i++)
    {
        c[i] += c[i - 1];
    }

    imprimir(c, k);

    int result[n];
    int current;
    for (int i = n - 1; i >= 0; i--)
    {
        current = v[i] - 1;
        result[c[current] - 1] = current;
        c[current]--;
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = result[i];
    }
}

int main()
{
    char str[1000];

    scanf("%s", str);
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }

    int nums[size];
    for (int i = 0; i < size; i++)
    {
        nums[i] = char_to_int(str[i]);
    }

    counting_sort(nums, size, 26);

    char result[1000];
    for (int i = 0; i < size; i++)
    {
        result[i] = int_to_char(nums[i]);
        printf("%c", int_to_char(nums[i] + 1));
    }
    printf("\n");

    return 0;
}