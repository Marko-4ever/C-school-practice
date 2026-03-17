#include <stdio.h>

struct Vrijeme
{
    int hour;
    int minute;
};

struct Pacijent
{
    char firstName[20+1];
    char lastName[20+1];
    int age;
    struct Vrijeme time;
}pac[30];

int main()
{
    int n, i=0;

    printf("Koliko ima pacijenata?: \n");
    scanf("%d", &n);

    do
    {
        printf("Unesi ime, prezime, godine i vrijeme termina(sat i minute): \n");
        scanf(" %s %s %d %d %d", pac[i].firstName, pac[i].lastName, &pac[i].age, &pac[i].time.hour, &pac[i].time.minute);
        i++;
    }
    while (i<n);

    i=0;
    do
    {
        if (pac[i].age >= 18)
        {
            if (pac[i].time.hour < 12)
            {
                printf("%s jutro\n", pac[i].lastName);
            }
            else if (pac[i].time.hour > 12)
            {
                printf("%s popodne\n", pac[i].lastName);
            }
        }
        else if (pac[i].age < 18)
        {
            if (pac[i].time.minute == 0)
            {
                printf("%s tocno\n", pac[i].lastName);
            }
            else if (pac[i].time.minute != 0)
            {
                printf("%s pomaknut termin\n", pac[i].lastName);
            }
        }
        i++;
    }
    while (i<n);

    for (i=0; i<n; i++)
    {
        if (pac[i].time.hour >= 10 && pac[i].time.hour <=14)
        {
            printf("%s\n", pac[i].lastName);
        }
    }
}
