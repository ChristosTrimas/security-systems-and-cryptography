#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void encryptDecrypt(char inpString[],char* key);

void main(int argc, char** argv)    
{
        FILE *f;
        int i=0;       
        char *key;
        char plaintext[10] = "Hello";
        int SALT_LEN = strlen(plaintext);
        key = (char*)malloc(sizeof(char)*SALT_LEN);

        /*open file */
        f = fopen("/dev/urandom", "r");

        while( i < SALT_LEN)  {
             key[i]  = fgetc(f);
             key[i] = abs(key[i]);

             if(fgetc(f) == EOF) {
                   exit(1);
             }
                printf("%d\n", key[i]);
                i++;
        }
        printf("The key is:%s\n", key);

        printf("Encrypted String: ");
        encryptDecrypt(plaintext,key);
        printf("\n");

        printf("Decrypted String :");
        encryptDecrypt(plaintext,key);
        printf("\n");


}

void encryptDecrypt(char inpString[],char* key)
{
        int len = strlen(inpString);
        int i;

        for (i=0; i < len; i++)
        {
                inpString[i] = inpString[i] ^ key[i];
        }

        printf("%s\n", inpString);                                   
}