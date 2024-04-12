#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
         h = get_int ("Heigth: ");
    }
    while(h<=0 || h>8 );  //this will prompt user to enter value between 0 and 8

    for (int i=0;i<=h;i++)
    {
        for(int d=0;d<h-i;d++) //this condition will print spaces
        {
            printf(" ");
        }

        for(int j=0;j<i;j++)
        {
            printf("#");
        }

        printf("  ");

        for(int j=0;j<i;j++)
        {
            printf("#");
        }

    printf("\n");

    }
}