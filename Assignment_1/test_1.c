#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void otp_encrypt_decrypt(char inpString[],char* key);

void main(int argc, char** argv)    
{
        
        int i = 0;       
        // char plaintext[10] = "Hello";
        
        // non buffer overflowed input
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
        // random generator
        FILE *f;
        char* key;
        int N = strlen(plaintext);
        key = (char*)malloc(sizeof(char)*N);

        //open file 
        f = fopen("/dev/urandom", "r");

        while( i < N)  {
             key[i]  = fgetc(f);
             key[i] = abs(key[i]);

             if(fgetc(f) == EOF) {
                   exit(1);
             }
                i++;
        }
        // for demo
        printf("Encrypted String: ");
        otp_encrypt_decrypt(plaintext,key);
        printf("\n");

        printf("Decrypted String :");
        otp_encrypt_decrypt(plaintext,key);
        printf("\n");

        free(plaintext);
        plaintext = NULL;
        return;

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