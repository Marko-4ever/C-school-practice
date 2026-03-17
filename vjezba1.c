#include <stdio.h>

struct Datum
{
    int dan, mjesec, godina;
};

struct Ispit
{
    char ime[20+1];
    char prezime[20+1];
    int ocjena;
    struct Datum datum;
}isp[35];

int main()
{
    int n, i;

    printf("Koliko ima ucenika: \n");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Unesi ime, prezime, ocjenu i datum pisanja drzavne mature za %d. ucenika: \n", i+1);
        scanf(" %s %s %d %d %d %d", isp[i].ime, isp[i].prezime, &isp[i].ocjena, &isp[i].datum.dan, &isp[i].datum.mjesec, &isp[i].datum.godina);
    }

    printf("A do P:\n");

    for (i=0; i<n; i++)
    {
        if (isp[i].prezime[0] >= 'A' && isp[i].prezime[0] <= 'P')
        {
            printf("%s %d\n", isp[i].prezime, isp[i].ocjena);
        }
    }

    printf("R do Z:\n");

    for (i=0; i<n; i++)
    {
        if (isp[i].prezime[0] >= 'R' && isp[i].prezime[0] <= 'Z')
        {
            if (isp[i].datum.mjesec == 6)
            {
                printf("%s ljetni rok\n", isp[i].prezime);
            }
            else if (isp[i].datum.mjesec == 8)
            {
                printf("%s jesenski rok\n", isp[i].prezime);
            }
        }
    }

    printf("Prosli sa 5:\n");

    for (i=0; i<n; i++)
    {
        if (isp[i].ocjena == 5)
        {
            printf("%s %d\n", isp[i].prezime, isp[i].datum.godina);
        }
    }
}