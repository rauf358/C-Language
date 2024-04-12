#include <cs50.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    string  text;
    int k;
    if ( argc == 2 )
   {
       if ( strlen(argv[1]) < 26)
       {
              printf("Key must contain 26 letters\n");
              return 1;
       }
     for ( int i = 0; i < strlen(argv[1]) ; i++ )
      {
           if ( isdigit(argv[1][i]) || isspace(argv[1][i]) || ispunct(argv[1][i]) )
           {
              printf("Key must contain alphabetic characters\n");
              return 1;
           }
         for ( k = i+1 ; k <= strlen(argv[1]) ; k++ )
           {
              if ( argv[1][i] == argv[1][k] && isupper(argv[1][k]) )//this will check alpahbet
                 {
                  printf("Keys must not be repeated\n");
                  return 1;
                 }
               else if ( argv[1][i] == argv[1][k] && islower(argv[1][k]) )//this will check case
                 {
                   printf("Keys must not be repeated\n");
                   return 1;
                 }
          }
          /*int in;
         if(isupper(argv[1][i]))
       {in=argv[1][i]-'A';
         printf("%i ",in);}
         if(islower(argv[1][i]))
       {in=argv[1][i]-'a';
         printf("%i ",in);}
*/

     }
     int index;
   //string  c = " ";
     text = get_string("plaintext: ");
     printf("ciphertext: ");
        for (int l=0;l<strlen(text);l++)
        {
          {
            if( isupper(text[l]) )

              {
                index = text[l]-'A';//this will calculate index num
                printf("%c",toupper(argv[1][index]));
                 }
            else if (  islower(text[l]) )
            {
              index = (text[l]-'a');
              printf("%c",tolower(argv[1][index]));
            }
            else
            {
               printf("%c",text[l]);
            }

        }

     }
      printf("\n");

   }
     else if ( argc == 1 || argc == 3)//this will provide eeror
   {
      printf("Usage:%s Key\n", argv[0]);
      return 1;
     }

        }
 /*

    }
printf(" %s\n ",text);*//*}*/