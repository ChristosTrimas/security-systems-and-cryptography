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

void main(int argc, char** argv)
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
    ceasars_cipher(1,plaintext,key);

    return;
}

void ceasars_cipher(int flag, char inpString[], int key)
{
	int i = 0 , j = strlen(inpString);

	if (flag == 0){	//encryption
		for (; i < j; i++)
	    {
	        // for lowercase letters
	        if (islower(inpString[i]) && isalpha(inpString[i]))
	        {
	            inpString[i] = (inpString[i] - 'a' + key) % 26 + 97;
	        }
	        
	        // for uppercase letters
	        else if(isupper(inpString[i]) && isalpha(inpString[i]))
	        {
	            inpString[i] = (inpString[i] - 'A' + key) % 26 + 65;
	        } 

	        else if(isdigit(inpString[i]))
	        {
	        	inpString[i] = (inpString[i] - '0' + key) % 26 + 48;
	        }     
	    }

	    printf("\n%s\n", inpString);
	}
	else{ 	//encryption
		for (; i < j; i++)
	    {
	        // for lowercase letters
	        if (islower(inpString[i]) && isalpha(inpString[i]))
	        {
	            inpString[i] = (inpString[i] - 'a' - key) % 26 + 97;
	        }
	        
	        // for uppercase letters
	        else if(isupper(inpString[i]) && isalpha(inpString[i]))
	        {
	            inpString[i] = (inpString[i] - 'A' - key) % 26 + 65;
	        }

	        else if(isdigit(inpString[i]))
	        {
	        	inpString[i] = (inpString[i] - '0' - key) % 26 + 48;
	        }      
	    }

	    printf("\n%s\n", inpString);
	}

}