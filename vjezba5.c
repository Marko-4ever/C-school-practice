#include <stdio.h>

struct Kategorija
{
    char oznaka;
    int prioritet;
};

struct Uredaj
{
    char naziv[20+1];
    int godina_izlaska;
    float cijena;
    struct Kategorija kat;
};

int main()
{
    struct Uredaj inventar[50];
    int n, i;

    printf("Koliko ima uredaja?: \n");
    scanf("%d", &n);

    printf("Unesi naziv, godinu izlaska, cijenu i kategoriju(oznaku i prioritet): \n");
    for (i=0; i<n; i++)
    {
        scanf(" %s %d %f %c %d", inventar[i].naziv, &inventar[i].godina_izlaska, &inventar[i].cijena, &inventar[i].kat.oznaka, &inventar[i].kat.prioritet);
    }

    printf("Consonants: \n");
    for (i=0; i<n; i++)
    {
        if (inventar[i].naziv[0] != 'A' && inventar[i].naziv[0] != 'E' && inventar[i].naziv[0] != 'I' && inventar[i].naziv[0] != 'O' && inventar[i].naziv[0] != 'U')
        {
            printf("%s, %.2f \n", inventar[i].naziv, inventar[i].cijena);
        }
    }

    printf("rang: \n");
    for (i=0; i<n; i++)
    {
        if (inventar[i].kat.prioritet %2 == 0 && inventar[i].godina_izlaska > 1995)
        {
            printf("%s, Moderni-P\n", inventar[i].naziv);
        }

        printf("%s\n", inventar[i].naziv);
    }

    printf("Lista: \n");
    for (i=0; i<n; i++)
    {
        if (inventar[i].kat.prioritet == 1)
        {
            printf("%s\n", inventar[i].naziv);
        }
    }
}