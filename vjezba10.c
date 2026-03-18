#include<stdio.h>

struct student
{
    char name[20+1];
    int sprint;
    int longJump;
    int situp;
    int avgscore;
};

struct class
{
    struct student st[5];
}cl[4];

int main()
{
    int i=0, j, maxscore=0, maxclass=0, maxstudent=0, passing=0;

    do
    {
        printf("Input name, sprint score, long jump score and situp score for each student(1-10) from class number %d: \n", i);
        j=0;
        while (j<5)
        {
            printf("Student number %d\n", j);
            scanf(" %s %d %d %d", cl[i].st[j].name, &cl[i].st[j].sprint, &cl[i].st[j].longJump, &cl[i].st[j].situp);
            cl[i].st[j].avgscore = (cl[i].st[j].sprint + cl[i].st[j].longJump + cl[i].st[j].situp)/3;
            if (cl[i].st[j].avgscore > 5)
            {
                passing++;
            }
            j++;
        }
        i++;
    }
    while (i<4);

    for (i=0;i<4;i++)
    {
        for (j=0;j<5;j++)
        {
            if (cl[i].st[j].avgscore > maxscore)
            {
                maxscore= cl[i].st[j].avgscore;
                maxclass=i;
                maxstudent=j;
            }
        }
    }

    printf("%s had the highest score out of everyone!\n", cl[maxclass].st[maxstudent].name);
    printf("%d students have passed!\n", passing);
}