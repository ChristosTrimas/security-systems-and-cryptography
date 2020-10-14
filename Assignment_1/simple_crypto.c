#include "simple_crypto.h"

char* randomGenerator(int N)
{
	FILE *f;
    char* key;
    int N = strlen(plaintext);
    key = (char*)malloc(sizeof(char)*N);

    //open file 
    f = fopen("/dev/urandom", "r");

    while( i < N)
    {
    	key[i]  = fgetc(f);
        key[i] = abs(key[i]);

        if(fgetc(f) == EOF) 
        {
        	exit(1)
        }
        i++;
    }
}

char* nonBufferedOvfInput()
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;
    
    char *plaintext = malloc(len_max);
    current_size = len_max;

    printf("\nInput:");

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
}

void otp_encrypt_decrypt(char inpString[],char* key)
{
    int len = strlen(inpString);
    int i;

    for (i=0; i < len; i++)
    {
        inpString[i] = inpString[i] ^ key[i];
    }

    printf("%s\n", inpString);                                   
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