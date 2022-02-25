#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 

typedef uint8_t BYTE;

int checkHeader(BYTE buff[]);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    // filter: Remember filenames
    char *infile = argv[1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int counter = 0;
    char * filename;

    while(!feof(inptr))
    {
        fread(buffer, sizeof(BYTE) * 512, 1, inptr);
        if (checkHeader(buffer) == 1)
        {
            //JPEG Header found. Check if a output file if open.
            
        }
        else
        {
            //Open the img file to write
            FILE *img = fopen(filename, "w");
        }   
            
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", counter);



            fwrite(buffer, sizeof(BYTE) * 512, 1, img);
            counter++;


        }
    
    }


    

     //   if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
      //  {
/*             for (int i = 0; i < 512; i++)
            {
            printf("%i : ", buffer[i]);
            counter ++;
            } */
//  }
    /* for (int i = 0; i < sizeof(buffer); i++)
    {
        if (buffer[i] != 0)
            printf ("%i", buffer[i]);
    } */

  //  }

   //}
    fclose(inptr);
    printf("\ncount: %i\n", counter);
    return 0;
}


int checkHeader(BYTE buff[])
{
    if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
    {   
        return 1;
    }
    else return 0;
}
