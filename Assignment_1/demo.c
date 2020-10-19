#include "simple_crypto.h"

void main()
{	
	char* plaintext;
	char* key;

	printf("\n[OTP] input: ");
	plaintext = nonBufferedOvfInput();

	key = randomGenerator(plaintext);

	printf("[OTP] encrypted: ");
    otp_encrypt_decrypt(plaintext,key);
    printf("\n");

    printf("[OTP] decrypted: ");
    otp_encrypt_decrypt(plaintext,key);
    printf("\n");

    free(plaintext);
    plaintext = NULL;
    return;
}