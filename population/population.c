#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    int end_size;
    int years=0;
    do
    {
        start_size=get_int("Start size: ");
    }while(start_size<9);
    do
    {
        end_size=get_int("End size: ");
    }while(end_size<start_size);

     while(start_size<end_size && years<end_size)
    {
         start_size= start_size +(start_size/3)-(start_size/4);
         years++;
    }
    printf("Years: %i ", years);
 }
