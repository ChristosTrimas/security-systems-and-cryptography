#ifndef SIMPLE_CRYPTO_H
#define SIMPLE_CRYPTO_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//helper functions
char* randomGenerator(int N);
char* nonBufferedOvfInput();

//assignment functions
void otp_encrypt_decrypt(char inpString[],char* key);

/*****************************************************
** One Time pad encryption/decryption algorithm      *
** 													 *
** Input: The plaintext for encryption or the cipher *
** text for decryption. Also the key.				 *				*
** 													 *
** Output: The encrypted cipher text or the original *
** plaintext.										 *
******************************************************/

void ceasars_cipher(int flag, char inpString[], int key);

/*****************************************************
** Caesars cipher encrypt/decrypt algorithm			 *
** 													 *
** Input: The plaintext for encryption or the cipher *
** text for decryption. Also the key. And a flag, 	 *								*
** which is 0 for encyption and 1 for decryption	 *												 *
** 													 *
** Output: The encrypted cipher text or the original *
** plaintext.										 *
******************************************************/

#endif