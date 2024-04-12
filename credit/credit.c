#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_num=369421438430814;

   /* do
    {
        credit_num = get_long("Number : ");
    }
    while(credit_num < 0);*/
    long first_digit = credit_num;
    long first_digit2=first_digit;
    long first_digit3=first_digit;
     int j;
     int y = 0;
     int k = 0;
     int z ;
     int k2 = 0;//number of digits
     int y1 = 0 ;
     int k1 = 0;
     while(credit_num > 0 )
     {
        j = credit_num%10;
        k++;
        if ((k%2)==0)
        {  j = j*2;    /// from this
            if(j>9)
            {
              z= j%10;
               j= j/10;
               j= j+z;
            }

        y= y+j;

        }       ///to this calculates sum of digits
        k1++;       ////from this
        if ((k1%2)!=0)
        {
            y1= y1+j;
        }               //// to this calculates checksum

        k2= k2+1;///num of digits
        credit_num= credit_num/10;
     }
    int b;
    int y3 = y+y1;
    if((y3%2)==0)
    {
         b = 1;
    }
    else
    {
         b = 0;
    }

    while(first_digit>10  )
    {
        first_digit/=10;
    }
    int num1=first_digit;

    if(k2==15 && b==1)
    {
        printf("AMEX\n");
    }
    else if(k2==16 && b==1 &&num1!=4 && num1==)
    {
        printf("MASTERCARD\n");
    }
    else if((k2==16 || k2==13) && num1==4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}