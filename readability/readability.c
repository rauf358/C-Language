#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string  t = get_string("Text: ");
    double l,s,w;
   double index,avgl,avgs;
    l = count_letters(t);
    s = count_sentences(t);
    w = count_words(t);
    avgl = (l/w)*100;
    avgs = (s/w)*100;
    index = (0.0588 * avgl) - (0.296 * avgs) - 15.8;
    int r =  (int) round(index);
    //printf("%lf\n",index);
    if(r>=1 && r<=16)
    {
        printf("Grade %i\n",r);
    }
    else if(r<1)
    {
        printf("Before Grade 1\n");
    }
    else if(r>16)
    {
        printf("Grade 16+\n");
    }

}
int count_letters(string text)
{
    int len = 0 ;
    for (int i=0;i<=strlen(text);i++)
    {
        if ((text[i] >='A' && text[i] <='Z') ||(text[i] >='a' && text[i] <='z') )
        {
            len++;
            continue;
        }
    }
    return len;
}
int count_words(string text)
{
int len=0;

    for (int i = 0;i <=strlen(text);i++)
    {
        if ((text[i] >='A' && text[i] <='Z') ||(text[i] >='a' && text[i] <='z') || (text[i] >='!' && text[i] <='a'))
        {
             continue;
        }
    if(text[i] ==' ' )
    {
        len++;
    }
    }int e = 1+len;
    return e;
}
int count_sentences(string text)
{
int len=0;
    for (int i = 0;i <=strlen(text);i++)
    {
        if ((text[i] >='A' && text[i] <='Z') ||(text[i] >='a' && text[i] <='z') || text[i] ==',' || text[i] ==' ')
        {
             continue;
        }
    if(text[i] =='!' || text[i] == '?' || text[i] =='.')
    {
        len++;
    }
    }
    return len;
}