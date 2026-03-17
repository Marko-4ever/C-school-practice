#include <stdio.h>

struct person
{
    char name[20+1];
    float snack_price[4];
    float combinedSpending;
    float avgSpending;
}p[10];

int main()
{
    int i=0, n, j;
    float temp=0;
    float day1[10];
    float day1avg[10] = {0};
    float day2[10];
    float day2avg[10] = {0};

    printf("How many people?: \n");
    scanf("%d", &n);

    printf("Day 1: \n");
    do
    {
        printf("Who was at the store: \n");
        scanf(" %s", p[i].name);
        j=0;
        while (j<4)
        {
            printf("Whats the price of the %d. item?: \n", j+1);
            scanf("%f", &p[i].snack_price[j]);
            temp += p[i].snack_price[j];
            day1avg[i] += p[i].snack_price[j];
            p[i].snack_price[j] = 0;
            j++;
        }
        day1[i] = temp;
        day1avg[i] = day1avg[i]/4;
        temp=0;
        i++;
    }
    while (i<n);

    printf("Day 2: \n");
    i=0;
    do
    {
        j=0;
        while (j<4)
        {
            printf("Whats the price of the %d. item?: \n", j+1);
            scanf("%f", &p[i].snack_price[j]);
            temp += p[i].snack_price[j];
            day2avg[i] += p[i].snack_price[j];
            p[i].snack_price[j] = 0;
            j++;
        }
        day2[i] = temp;
        day2avg[i] = day2avg[i]/4;
        temp=0;
        i++;
    }
    while (i<n);

    for (i=0; i<n; i++)
    {
        p[i].combinedSpending = day1[i]+day2[i];
        p[i].avgSpending = (day1avg[i]+day2avg[i])/2;
    }

    int maxIndex = 0;
    for (i=0; i<n; i++)
    {
        if (p[i].combinedSpending > p[maxIndex].combinedSpending)
        {
            maxIndex = i;
        }
    }

    printf("%s spent the most money\n", p[maxIndex].name);
    for (i=0; i<n; i++)
    {
        printf("%.2f was the average price for a snack for %s", p[i].avgSpending, p[i].name);
    }
}