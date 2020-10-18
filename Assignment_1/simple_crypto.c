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

void ceasars_cipher(char inpString[], int key)
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


    for(i=0;i<strlen(newCharacter);i++)
    {
        for(j=0;j<62;j++)
        {
            if(newCharacter[i] == newAlphabet[j])
            {                   
                inpString[i] = newAlphabet[(j-key+62)%62];

                printf("%c",inpString[i]);
            }
        }
    }
    printf("\n");
}

void vigenere(int flag, char inpString[], char* key)
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

	// newKey[i] = '\0';
	if (flag == 0){
		for (i=0; i < ptLength; i++)
		{
			inpString[i] = ((inpString[i] + newKey[i]) % 26) +'A';
		}
	}
	
	else
	{
		for (i = 0; i < ptLength; i++)
		{
			inpString[i] = (((inpString[i] - newKey[i]) + 26) % 26) + 'A';
		}
	}

	printf("%s\n", inpString);
}