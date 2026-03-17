#include <stdio.h>

struct Stock
{
    int beansWeight, milkCans;
};

struct Order
{
    int orderID;
    struct Stock ingredients;
    float price;
}orders;

int processTransaction(float *PcB);

int main()
{
    float customerBalance;
    float *PcB = &customerBalance;
    struct Stock pantry;

    pantry.beansWeight = 500;
    pantry.milkCans = 10;

    printf("Whats your balance?: \n");
    scanf("%f", &customerBalance);

    orders.orderID = 101;
    orders.price = 4.50;
    orders.ingredients.beansWeight = 50;
    orders.ingredients.milkCans = 1;

    if (pantry.beansWeight >= orders.ingredients.beansWeight && pantry.milkCans >= orders.ingredients.milkCans)
    {
        processTransaction(&customerBalance);

        pantry.beansWeight -= orders.ingredients.beansWeight;
        pantry.milkCans -= orders.ingredients.milkCans;
    }

    printf("%d, %d, %.2f", pantry.beansWeight, pantry.milkCans, customerBalance);
}

int processTransaction(float *PcB)
{
    *PcB = *PcB - orders.price;

    if (*PcB > 0)
    {
        return 1;
    }

    return -1;
}