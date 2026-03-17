#include <stdio.h>

struct Coords
{
    int x, y;
};

struct Star
{
    int ID;
    struct Coords pos;
    int Brightness, Distance;
}star[20];

int main()
{
    int i, n, SignalScore[20];

    printf("Koliko je zvijezdi?: \n");
    scanf("%d", &n);

    printf("Unesi ID, koordinate(x i y), jacinu svjetla i udaljenost zvijezde: \n");

    for (i=0; i<n; i++)
    {
        scanf("%d %d %d %d %d", &star[i].ID, &star[i].pos.x, &star[i].pos.y, &star[i].Brightness, &star[i].Distance);
    }

    for (i=0; i<n; i++)
    {
        SignalScore[i] = star[i].Brightness * star[i].Distance;
        if (star[i].ID%2 == 0)
        {
            SignalScore[i] *=2;
        }

        if (star[i].pos.x == star[i].pos.y)
        {
            SignalScore[i] += 100;
        }

        if (star[i].Distance == 0)
        {
            SignalScore[i] = -1;
        }
    }

    for (i=0; i<n; i++)
    {
        printf("%d\n", SignalScore[i]);
    }
}