#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


void vigenere(int flag, char inpString[], char* key);

void main(int argv, char** argc)
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;
    
    char *plaintext = malloc(len_max);
    current_size = len_max;

    printf("\nInput: ");

    if (plaintext != NULL)
    {
            int c = EOF;
            unsigned int i =0;
            //accept user input until hit enter or end of file
            while (( c = toupper(getchar() )) != '\n' && c != EOF)
            {
                plaintext[i++]=(char)c;

                //if i reached maximize size then realloc size
                if (i == current_size)
                {
                    current_size = i+len_max;
                    plaintext = realloc(plaintext, current_size);
                }
            }

            plaintext[i] = '\0';
    }

    //for demo with the generaor above
    printf("\nKey: ");
	len_max = 128;
    current_size = 0;
    
    char *key = malloc(len_max);
    current_size = len_max;

    if (key != NULL)
    {
            int c = EOF;
            unsigned int i =0;
            //accept user input until hit enter or end of file
            while (( c = toupper(getchar() )) != '\n' && c != EOF)
            {
                key[i++]=(char)c;

                //if i reached maximize size then realloc size
                if (i == current_size)
                {
                    current_size = i+len_max;
                    key = realloc(key, current_size);
                }
            }

            key[i] = '\0';
    }

    vigenere(plaintext,key);
    return;
}

void vigenere(char inpString[], char* key)
{
	int ptLength = strlen(inpString);
	int keyLength = strlen(key);
	int i = 0, j = 0;
	char newKey[ptLength];

	for (;i < ptLength; i++,j++)
	{
		if (j == keyLength)
			j = 0;

		newKey[i] = key[j];
	}

	printf("\n[Vigenere] encrypted: ");
	for (i=0; i < ptLength; i++)
    {
        inpString[i] = ((inpString[i] + newKey[i]) % 26) +'A';
    }
    printf("\n");
    
    printf("\n[Vigenere] decrypted: ");	
	for (i = 0; i < ptLength; i++)
    {
        inpString[i] = (((inpString[i] - newKey[i]) + 26) % 26) + 'A';
    }

	printf("%s\n", inpString);
}
