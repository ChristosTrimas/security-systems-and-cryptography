#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void ceasars_cipher(int flag, char inpString[], int key);

int main(int argc, char** argv)
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;
    
    char *plaintext = malloc(len_max);
    current_size = len_max;

    printf("\nInput: ");

    if(plaintext != NULL)
    {
            int c = EOF;
            unsigned int i =0;
            //accept user input until hit enter or end of file
            while (( c = getchar() ) != '\n' && c != EOF)
            {
                plaintext[i++]=(char)c;

                //if i reached maximize size then realloc size
                if(i == current_size)
                {
                    current_size = i+len_max;
                    plaintext = realloc(plaintext, current_size);
                }
            }

            plaintext[i] = '\0';
    }
    //for demo with the generaor above
    printf("\nKey: ");
    int key;
    scanf("%d",&key);

    ceasars_cipher(0,plaintext,key);
    // ceasars_cipher(1,plaintext,key);
    free(plaintext);

    return 0;
}

void ceasars_cipher(int flag, char inpString[], int key)
{
    char newAlphabet[62],newCharacter[strlen(inpString)];
    int i,j;
    //maybe a func?
    for(j=0,i=48;j<10;j++)
    {
        newAlphabet[j] = i;
        i++;
    } 

    for(i=65;j<36;j++)
    {
        newAlphabet[j] = i;
        i++;
    }
    for(i=97;j<62;j++)
    {
        newAlphabet[j] = i;
        i++;
    }

    i=0,j=0;

    for(i=0;i<strlen(inpString);i++)
    {
        for(j=0;j<62;j++)
        {
            if(inpString[i] == newAlphabet[j])
            {                   
                newCharacter[i] = newAlphabet[(j+key)%62];
                printf("%c",newCharacter[i]);
            }
        }
    }
    printf("\n");
}