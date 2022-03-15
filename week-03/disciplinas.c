#include <stdlib.h>
#include <stdio.h>
// #include "disciplinas.h"

typedef struct Disciplina Disciplina;
struct Disciplina
{
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

typedef struct Curso Curso;
struct Curso
{
    int cod_curso;
    char *nome_curso;
    Disciplina *ultima_disciplina;
};

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

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina)
{
    Disciplina *d = curso->ultima_disciplina;
    while (1)
    {
        int val = compara_strings(nova_disciplina->nome, d->nome);
        if (val > 0)
        {
            break;
        }

        if (d->requisito == NULL)
        {
            d->requisito = nova_disciplina;
            return;
        }

        d = d->requisito;
    }

    if (compara_strings(nova_disciplina->nome, curso->ultima_disciplina->nome) > 0)
    {
        nova_disciplina->requisito = curso->ultima_disciplina;
        curso->ultima_disciplina = nova_disciplina;
        return;
    }

    if (compara_strings(nova_disciplina->nome, curso->ultima_disciplina->requisito->nome) > 0)
    {
        nova_disciplina->requisito = curso->ultima_disciplina->requisito;
        curso->ultima_disciplina->requisito = nova_disciplina;
        return;
    }

    if (compara_strings(nova_disciplina->nome, curso->ultima_disciplina->requisito->requisito->nome) > 0)
    {
        nova_disciplina->requisito = curso->ultima_disciplina->requisito->requisito;
        curso->ultima_disciplina->requisito->requisito = nova_disciplina;
        return;
    }

    if (compara_strings(nova_disciplina->nome, curso->ultima_disciplina->requisito->requisito->requisito->nome) > 0)
    {
        nova_disciplina->requisito = curso->ultima_disciplina->requisito->requisito->requisito;
        curso->ultima_disciplina->requisito->requisito->requisito = nova_disciplina;
        return;
    }

    if (compara_strings(nova_disciplina->nome, curso->ultima_disciplina->requisito->requisito->requisito->requisito->nome) > 0)
    {
        nova_disciplina->requisito = curso->ultima_disciplina->requisito->requisito->requisito->requisito;
        curso->ultima_disciplina->requisito->requisito->requisito->requisito = nova_disciplina;
        return;
    }

    if (compara_strings(nova_disciplina->nome, curso->ultima_disciplina->requisito->requisito->requisito->requisito->requisito->nome) > 0)
    {
        nova_disciplina->requisito = curso->ultima_disciplina->requisito->requisito->requisito->requisito->requisito;
        curso->ultima_disciplina->requisito->requisito->requisito->requisito->requisito = nova_disciplina;
        return;
    }

    // Disciplina *d2 = curso->ultima_disciplina->requisito;
    // while (d2 != NULL)
    // {
    //     if (compara_strings(d2->nome, nova_disciplina->nome) > 0)
    //     {
    //         nova_disciplina->requisito = d2->requisito;
    //         d2->requisito = nova_disciplina;
    //         return;
    //     }
    //     d2 = d2->requisito;
    // }
}

// --- Input ---
// 99 Disciplina15 1
// 1 Curso
// 2
// 10 Disciplina10 4
// 20 Disciplina20 6

// --- Expected output (exact text)---
// cod=10 nome=Disciplina10 creditos=4
// cod=99 nome=Disciplina15 creditos=1
// cod=20 nome=Disciplina20 creditos=6
int main()
{
    Disciplina d;
    d.cod = 99;
    char d_nome[] = "Disciplina15";
    d.nome = &d_nome;
    d.creditos = 1;

    Disciplina d2;
    d2.cod = 10;
    char d2_nome[] = "Disciplina10";
    d2.nome = &d2_nome;
    d2.creditos = 4;

    Disciplina d3;
    d3.cod = 20;
    char d3_nome[] = "Disciplina20";
    d3.nome = &d3_nome;
    d3.creditos = 6;
    d3.requisito = &d2;

    Curso c;
    c.cod_curso = 1;
    c.nome_curso = "Curso";
    c.ultima_disciplina = &d3;

    // printf("%d \n", compara_strings(d2_nome, d3_nome));
    // printf("%d \n", compara_strings(d3_nome, d3_nome));
    // printf("%d \n", compara_strings(d3_nome, d2_nome));
    insere_disciplina(&c, &d);
    return 0;
}