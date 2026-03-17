#include <stdio.h>

struct Mjerenje
{
    char lokacija[20+1];
    int temp_jutro, temp_podne, temp_vecer;
    int invalid_br;
}lok[15];

int main()
{
    int n, i, br=0;
    float avg_temp[15];

    printf("Koliko ima lokacija?: \n");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Unesi ime lokacije i temperature za jutro, podne i vecer i zapocni brojac sa 0: \n");
        scanf(" %s %d %d %d %d", lok[i].lokacija, &lok[i].temp_jutro, &lok[i].temp_podne, &lok[i].temp_vecer, &lok[i].invalid_br);
    }

    for (i=0; i<n; i++)
    {
        if ((lok[i].temp_jutro < -50 || lok[i].temp_jutro > 50) || (lok[i].temp_podne < -50 || lok[i].temp_podne > 50) || (lok[i].temp_vecer < -50 || lok[i].temp_vecer > 50))
        {
            lok[i].invalid_br = 1;
            br ++;
        }

        avg_temp[i] = (float)(lok[i].temp_jutro + lok[i].temp_podne + lok[i].temp_vecer)/3;

        if (lok[i].invalid_br != 1 && lok[i].temp_podne > avg_temp[i])
        {
            printf("%s %.1f\n", lok[i].lokacija, avg_temp[i]);
        }
    }

    printf("%d\n", br);
}