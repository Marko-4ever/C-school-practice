#include<stdio.h>

struct Person
{
    char name[20+1];
    float dishPrice[3];
    float totalSpending;
    float avgCost;
}p[3];

int main()
{
    int j, i;
    int cheapPerson =0;
    float minPrice =99999;

    for (int k=0; k<4; k++)
    {
        printf("Week %d: \n", k+1);
        i=0;
        do
        {
            if (k == 0)
            {
                printf("Name of the person: \n");
                scanf(" %s", p[i].name);
            }
            j=0;
            while (j<3)
            {
                printf("Dish #%d. price: \n", j+1);
                scanf("%f", &p[i].dishPrice[j]);
                p[i].totalSpending += p[i].dishPrice[j];
                if (p[i].dishPrice[j] < minPrice)
                {
                    minPrice = p[i].dishPrice[j];
                    cheapPerson = i;
                }
                p[i].dishPrice[j] = 0;
                j++;
            }
            i++;
        }
        while (i<3);
    }

    int max=0;
    for (i=0; i<3; i++)
    {
        if (p[i].totalSpending > p[max].totalSpending)
        {
            max = i;
        }
        p[i].avgCost = p[i].totalSpending/12;
    }

    printf("%s spent the most on groceries\n", p[max].name);
    printf("%s had the cheapest single dish across the entire month\n", p[cheapPerson].name);
    for (i=0; i<3; i++)
    {
        printf("%s's average was %.2f\n", p[i].name, p[i].avgCost);
    }
}