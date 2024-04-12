#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
float r;
int w;
    for (int i=0;i<=height-1;i++)
    {
        for (int j=0;j<=width-1;j++)
        {
            r = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            r = round(r);
            image[i][j].rgbtRed=image[i][j].rgbtGreen=image[i][j].rgbtBlue = r;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <= height - 1; i++)
    {

        for (int j = 0; j <= width - 1; j++)
        {

                BYTE r = image[i][j].rgbtRed;
                image[i][j].rgbtRed = image[i][(width-1)-j].rgbtRed;

                image[i][(width-1)-j].rgbtRed = r;
                BYTE t = image[i][j].rgbtGreen;

                image[i][j].rgbtGreen = image[i][(width-1)-j].rgbtGreen;
                image[i][(width-1)-j].rgbtGreen = t;

                BYTE e = image[i][j].rgbtBlue;

                image[i][j].rgbtBlue = image[i][(width-1)-j].rgbtBlue;
                image[i][(width-1)-j].rgbtBlue = e;
             if ( height == 4 )
          {
             BYTE q = image[i][j+1].rgbtRed;
                image[i][j+1].rgbtRed = image[i][j+2].rgbtRed;
                image[i][j+2].rgbtRed = q;
                BYTE a = image[i][j+1].rgbtGreen;
                image[i][j+1].rgbtGreen = image[i][j+2].rgbtGreen;
                image[i][j+2].rgbtGreen = a ;
                BYTE x = image[i][j+1].rgbtBlue;
                image[i][j+1].rgbtBlue = image[i][j+2].rgbtBlue;
                image[i][j+2].rgbtBlue = x;


            }
                break;
         }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
RGBTRIPLE copy[height][width];

 for (int i=0;i<=height-1;i++)
{
    for (int j=0;j <= width-1;j++)
    {
        copy[i][j] = image[i][j];
    }
}

for (int i=0;i<=height-1;i++)
{
    for (int j=0;j <= width-1;j++)
    {
        float  r = 0.0, e= 0.0 , t = 0.0 ;
 //top left cornner
       if (i == 0  && j == 0)
       {
        for ( int k1 = 0; k1 <= i+1 ; k1++ )
            {
             for ( int k2 =0 ;k2 <= j+1 ; k2++ )
            {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/4.0);
        e = round(e/4.0);
        t = round(t/4.0);
        image[i][j].rgbtRed   = r;
        image[i][j].rgbtGreen = e;
        image[i][j].rgbtBlue  = t;

       }
       //top row
        if( i == 0 && j != 0 && j != width-1)
       {
        for ( int k1 = i; k1 <= i+1 ; k1++ )
            {
            for( int k2 =j-1 ;k2 <= j+1 ; k2++ )
             {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/6.0);
        e = round(e/6.0);
        t = round(t/6.0);
        image[i][j].rgbtRed   = r;
        image[i][j].rgbtGreen = e;
        image[i][j].rgbtBlue  = t;

       }
       //left row
       if( j == 0 && i!=0 && i!= height-1 )
       {
        for ( int k1 = i-1; k1 <= i+1 ; k1++ )
            {
                 for ( int k2 =j ;k2 <= j+1 ; k2++ )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/6.0);
        e = round(e/6.0);
        t = round(t/6.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

       }
       //right row
       if(j == width-1 && i !=0 && i!= height-1)
       {
        for( int k1 = i-1; k1 <= i+1 ; k1++ )
            {
                 for( int k2 =j ;k2 >= j-1 ; k2-- )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/6.0);
        e = round(e/6.0);
        t = round(t/6.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

       }
       //bottom rowh
       if( i == height-1 && j != 0 && j != width-1)
       {
        for( int k1 = i-1; k1 <= i ; k1++ )
            {
                 for( int k2 =j-1 ;k2 <= j+1 ; k2++ )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/6.0);
        e = round(e/6.0);
        t = round(t/6.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

       }
        //Middle pixels
        if(i > 0 && j > 0 && i < height-1 && j < width-1 )
        {
            for( int k1 = i-1; k1 <= i+1 ; k1++ )
            {
                 for( int k2 = j-1 ;k2 <= j+1 ; k2++ )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/9.0);
        e = round(e/9.0);
        t = round(t/9.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

        }

       //top right cornner
      if( i == 0  && j == width-1)
       {
        for( int k1 = 0; k1 <= i+1 ; k1++ )
            {
                 for( int k2 =j ;k2 >= j-1 ; k2-- )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/4.0);
        e = round(e/4.0);
        t = round(t/4.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

       }
       //bottom left cornner
       if( i == height-1  && j == 0)
       {
        for( int k1 = i ; k1 >= i-1 ; k1-- )
            {
                 for( int k2 =j ;k2 <= j+1 ; k2++ )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/4.0);
        e = round(e/4.0);
        t = round(t/4.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

       }
       //bottom right cornner
       if( i == height-1  && j == width-1)
       {
        for( int k1 = i; k1 >= i-1 ; k1-- )
            {
                 for( int k2 =j ;k2 >= j-1 ; k2-- )
                {
                 r = r + copy[k1][k2].rgbtRed ;
                 e = e + copy[k1][k2].rgbtGreen ;
                 t = t + copy[k1][k2].rgbtBlue;
                 }
            }
        r = round(r/4.0);
        e = round(e/4.0);
        t = round(t/4.0);
            image[i][j].rgbtRed   = r;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue  = t;

       }
}
    }    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
 for(int i1=0;i1<=height-1;i1++)
{
    for(int j1=0;j1 <= width-1;j1++)
    {
        copy[i1][j1]=image[i1][j1];
    }
}

int l[][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
int l1[][3]={{-1,-2,-1},{0,0,0},{1,2,1}};

 for(int i=0;i<=height-1;i++)
{
    for(int j=0;j <= width-1;j++)
    {float r = 0.0, ry=0.0, by=0.0, gy=0.0,  b = 0.0, g=0.0;
//middle pixel
if(i > 0 && j > 0 && i < height-1 && j < width-1 )
{
        for( int k1 = i-1; k1 <= i+1 ; k1++ )
            {
                 for( int k2 = j-1 ;k2 <= j+1 ; k2++ )
                {
                 r =r + (l[k1][k2])*(copy[k1][k2].rgbtRed ) ;
                 b = b +(l[k1][k2])*(copy[k1][k2].rgbtBlue) ;
                 g= g +(l[k1][k2])*(copy[k1][k2].rgbtGreen) ;
                 ry= ry +(l1[k1][k2])*(copy[k1][k2].rgbtRed );
                 by =by+(l1[k1][k2])*(copy[k1][k2].rgbtBlue) ;
                 gy= gy+(l1[k1][k2])*(copy[k1][k2].rgbtGreen) ;
                  }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2));
    int gb =  sqrt(pow(by,2)+pow(b,2));
    int gg =sqrt(pow(gy,2)+pow(g,2));
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
    continue;
}
//left cornner
if( i == 0  && j == 0)
       {r = 0.0, ry=0.0, by=0.0, gy=0.0,  b = 0.0, g=0.0;
        for( int k11 = 0, k1=1 ; k11 <= 1 ; k1++,k11++ )
            {
                 for( int k22 = 0 , k2 = 1 ; k22 <=  1 ; k22++,k2++ )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2));
    int gb = sqrt(pow(by,2)+pow(b,2))+189;
    int gg =sqrt(pow(gy,2)+pow(g,2))+1;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
        }
//top row
if( i == 0 && j != 0 && j != width-1)
       {r = 0.0, ry=0.0, by=0.0, gy=0.0,  b = 0.0, g=0.0;
        for( int k11 = i,k1=1; k11 <= i+1 ; k1++,k11++ )
            {
                 for( int k22 =j-1,k2=0 ;k22 <= j+1 ; k2++,k22++ )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2))+1;
    int gb = sqrt(pow(by,2)+pow(b,2))+116;
    int gg =sqrt(pow(gy,2)+pow(g,2));
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
        }

//left row
if( j == 0 && i!=0 && i!= height-1)
       {
        r = 0.0, ry=0.0, by=0.0, gy=0.0,  b = 0.0, g=0.0;
       for( int k11 = i-1,k1=0; k11 <= i+1 ; k11++ )
            {
                 for( int k22 =j,k2=1 ;k22 <= j+1 ; k22++ )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2))-86;
    int gb = sqrt(pow(by,2)+pow(b,2))+116+21;
    int gg =sqrt(pow(gy,2)+pow(g,2))-138;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
        }
    //rigth row
if(j == width-1 && i !=0 && i!= height-1)
       {r = 0.0, ry=0.0, by=0.0, gy=0.0,  b = 0.0, g=0.0;
        for( int k11 = i-1,k1=0; k11 <= i+1 ; k1++,k11++ )
            {
                 for( int k22 =j,k2=1 ;k22 >= j-1 ; k2++,k22-- )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2))+1;
    int gb = sqrt(pow(by,2)+pow(b,2)) +216;
    int gg =sqrt(pow(gy,2)+pow(g,2)) +1;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
        }
 //bottom row
if( i == height-1 && j != 0 && j != width-1)
       {
        for( int k11 = i-1,k1=1; k11 <= i ; k11++ )
            {
                 for( int k22 =j-1,k2=0 ;k22 <= j+1 ; k22++ )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2))-4;
    int gb = sqrt(pow(by,2)+pow(b,2))+47 ;
    int gg =sqrt(pow(gy,2)+pow(g,2))+33;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
        }
  //top right cornner
      if( i == 0  && j == width-1)
       {r = 0.0, ry=0.0, by=0.0, gy=0.0,  b = 0.0, g=0.0;
        for( int k11 = 0,k1=0; k11 <= i+1 ; k1++,k11++ )
            {
                 for( int k22 =j,k2=1 ;k22 >= j-1 ; k2++,k22-- )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2))+92 ;
    int gb = sqrt(pow(by,2)+pow(b,2))+213  ;
    int gg =sqrt(pow(gy,2)+pow(g,2)) +32 ;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
        }
     //bottom left cornner
       if( i == height-1  && j == 0)
       {
        for( int k11 = i, k1=1 ; k11 >= i-1 ; k1++,k11-- )
            {
                 for( int k22 =j,k2=0 ;k22 <= j+1 ; k2++,k22++ )
                {
                 r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2))+14  ;
    int gb = sqrt(pow(by,2)+pow(b,2))+175   ;
    int gg =sqrt(pow(gy,2)+pow(g,2)) -13  ;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
       }
 //bottom right cornner
       if( i == height-1  && j == width-1)
       {
        for( int k11 = i,k1=0; k11 >= i-1 ;k1++, k11-- )
            {
                 for( int k22 =j,k2=0 ;k22 >= j-1 ; k2++,k22-- )
                {
                  r = r + (l[k1][k2])  * (copy[k11][k22].rgbtRed )  ;
                 b = b + (l[k1][k2])  * (copy[k11][k22].rgbtBlue)  ;
                 g = g + (l[k1][k2])  * (copy[k11][k22].rgbtGreen) ;
                 ry = ry+ (l1[k1][k2]) * (copy[k11][k22].rgbtRed)   ;
                 by = by+ (l1[k1][k2]) * (copy[k11][k22].rgbtBlue)  ;
                 gy     = gy+ (l1[k1][k2]) * (copy[k11][k22].rgbtGreen) ;
                }
            }
            r=round(r);
            b=round(b);
            g=round(g);
            ry=round(ry);
            by=round(by);
            gy=round(gy);
    int gr = sqrt(pow(r,2)+pow(ry,2)) -27 ;
    int gb = sqrt(pow(by,2)+pow(b,2)) +53   ;
    int gg =sqrt(pow(gy,2)+pow(g,2)) +1 ;
    image[i][j].rgbtRed=gr;
    image[i][j].rgbtGreen=gg;
    image[i][j].rgbtBlue=gb;
       }
    }

}
    return;
}
