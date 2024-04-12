#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
 if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
 FILE* input = fopen(argv[1],"r");
  if (input == NULL)
  {
    printf("Forensic image cannot be opened\n");
    return 1;
  }

  uint8_t b[512];
  char s[10];
  int i = 0;
  while(fread(b,512,1,input) != EOF)
  {
    if (b[0] == 0xff && b[1] == 0xd8 && b[2] == 0xff && (b[3] <= 0xe0 || b[3] >= 0xef))
      {
        sprintf(s,"%03i.jpg",i);
        FILE *output = fopen("output.JPG","w");
        fwrite()
      }
  }


  fclose(input);
}