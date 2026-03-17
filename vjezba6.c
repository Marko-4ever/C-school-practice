#include<stdio.h>

struct Oprema
{
    float tezina;
    char kod_tipa;
};

struct Expedicija
{
    char naziv_tima[20+1];
    char kontinent[10+1];
    int broj_clanova;
    struct Oprema opr;
};

void dataReading(char naziv[], char kont[], int *br, float *tez, char *kod);

int main()
{
    int n, i;
    struct Expedicija exp[20];

    printf("Koliko expedicija?: \n");
    scanf("%d", &n);

    printf("Unesi naziv tima, kontinent, broj clanova, tezinu i kod: \n");
    for (i=0; i<n; i++)
    {
        dataReading(exp[i].naziv_tima, exp[i].kontinent, &exp[i].broj_clanova, &exp[i].opr.tezina, &exp[i].opr.kod_tipa);
    }

    printf("Antarktika?: \n");
    for (i=0; i<n; i++)
    {
        if (exp[i].kontinent == "Antarktika" && exp[i].opr.tezina > 500.0)
        {
            printf("%s, %s\n", exp[i].naziv_tima, exp[i].kontinent);
        }
    }

    printf("Tim category: \n");
    for (i=0; i<n; i++)
    {
        if (exp[i].broj_clanova %2 == 0 && (exp[i].opr.kod_tipa >= 'A' && exp[i].opr.kod_tipa <= 'Z'))
        {
            printf("%s-Elite\n", exp[i].naziv_tima);
        }
        else if (exp[i].broj_clanova %2 != 0)
        {
            printf("%s-Standard\n", exp[i].naziv_tima);
        }
        else
        {
            printf("%s", exp[i].naziv_tima);
        }
    }

    printf("lista: \n");
    for (i=0; i<n; i++)
    {
        if ((exp[i].broj_clanova*exp[i].broj_clanova) == exp[i].opr.tezina && exp[i].kontinent[0] == 'A')
        {
            printf("%s\n", exp[i].naziv_tima);
        }
    }
}

void dataReading(char naziv[], char kont[], int *br, float *tez, char *kod)
{
    scanf(" %s %s %d %f %c", naziv, kont, br, tez, kod);
}


