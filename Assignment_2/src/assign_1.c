#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/cmac.h>

#define BLOCK_SIZE 16


/* function prototypes */
void print_hex(unsigned char *, size_t);
void print_string(unsigned char *, size_t); 
void usage(void);
void check_args(char *, char *, unsigned char *, int, int);
void keygen(unsigned char *, unsigned char *, unsigned char *, int);
void encrypt(unsigned char *, int, unsigned char *, unsigned char *, 
    unsigned char *, int );
int decrypt(unsigned char *, int, unsigned char *, unsigned char *, 
    unsigned char *, int);
void gen_cmac(unsigned char *, size_t, unsigned char *, unsigned char *, int);
int verify_cmac(unsigned char *, unsigned char *);



/* TODO Declare your function prototypes here... */

//could be in a .h file for cleaner code

unsigned char *readText(char* ,unsigned long *);
void writeText(char* ,unsigned char *, unsigned long );
EVP_CIPHER *bit_check(int bit_mode);
/*
 * Prints the hex value of the input
 * 16 values per line
 */
void
print_hex(unsigned char *data, size_t len)
{
	size_t i;

	if (!data)
		printf("NULL data\n");
	else {
		for (i = 0; i < len; i++) {
			if (!(i % 16) && (i != 0))
				printf("\n");
			printf("%02X ", data[i]);
		}
		printf("\n");
	}
}


/*
 * Prints the input as string
 */
void
print_string(unsigned char *data, size_t len)
{
	size_t i;

	if (!data)
		printf("NULL data\n");
	else {
		for (i = 0; i < len; i++)
			printf("%c", data[i]);
		printf("\n");
	}
}


/*
 * Prints the usage message
 * Describe the usage of the new arguments you introduce
 */
void
usage(void)
{
	printf(
	    "\n"
	    "Usage:\n"
	    "    assign_1 -i in_file -o out_file -p passwd -b bits" 
	        " [-d | -e | -s | -v]\n"
	    "    assign_1 -h\n"
	);
	printf(
	    "\n"
	    "Options:\n"
	    " -i    path    Path to input file\n"
	    " -o    path    Path to output file\n"
	    " -p    psswd   Password for key generation\n"
	    " -b    bits    Bit mode (128 or 256 only)\n"
	    " -d            Decrypt input and store results to output\n"
	    " -e            Encrypt input and store results to output\n"
	    " -s            Encrypt+sign input and store results to output\n"
	    " -v            Decrypt+verify input and store results to output\n"
	    " -h            This help message\n"
	);
	exit(EXIT_FAILURE);
}


/*
 * Checks the validity of the arguments
 * Check the new arguments you introduce
 */
void
check_args(char *input_file, char *output_file, unsigned char *password, 
    int bit_mode, int op_mode)
{
	if (!input_file) {
		printf("Error: No input file!\n");
		usage();
	}

	if (!output_file) {
		printf("Error: No output file!\n");
		usage();
	}

	if (!password) {
		printf("Error: No user key!\n");
		usage();
	}

	if ((bit_mode != 128) && (bit_mode != 256)) {
		printf("Error: Bit Mode <%d> is invalid!\n", bit_mode);
		usage();
	}

	if (op_mode == -1) {
		printf("Error: No mode\n");
		usage();
	}
}


/*
 * Generates a key using a password
 */
void
keygen(unsigned char *password, unsigned char *key, unsigned char *iv,
    int bit_mode)
{

	/* TODO Task A */
	const EVP_CIPHER* cipher;
	const EVP_MD* hash_func = NULL;

	//first check the bit mode
	if (bit_mode == 128)
	{
		cipher = EVP_get_cipherbyname("aes-128-ecb");
	}
	else if (bit_mode == 256)
	{
		cipher = EVP_get_cipherbyname("aes-256-ecb");
	}
	else
	{
		fprintf(stderr,"Something went wrong with the bit size.\n");
		exit(1);
	}
	
	hash_func = EVP_sha1();

	//no salt
	EVP_BytesToKey(cipher, hash_func, NULL, password, strlen((const char*) password), 1, key, iv);
	printf("\nHex key:"); //delete this before sending zip
	print_hex(key, bit_mode / 8);

}


/*
 * Encrypts the data
 */
void
encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
    unsigned char *iv, unsigned char *ciphertext, int bit_mode)
{

	/* TODO Task B */
	EVP_CIPHER_CTX* ctx;
	const EVP_CIPHER* cipher;
	int len;

	ctx = EVP_CIPHER_CTX_new();

	if (bit_mode == 128)
	{
		cipher = EVP_get_cipherbyname("aes-128-ecb");
	}
	else if (bit_mode == 256)
	{
		cipher = EVP_get_cipherbyname("aes-256-ecb");
	}
	else
	{
		fprintf(stderr,"Something went wrong with the bit size.\n");
		exit(1);
	}

	EVP_EncryptInit_ex(ctx, cipher, NULL, key, NULL);
	EVP_EncryptUpdate(ctx,ciphertext,&len,plaintext,plaintext_len);
	EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);

	EVP_CIPHER_CTX_free(ctx);
}


/*
 * Decrypts the data and returns the plaintext size
 */
int
decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
    unsigned char *iv, unsigned char *plaintext, int bit_mode)
{
	int plaintext_len;
	// EVP_CIPHER_CTX* ctx;

	plaintext_len = 0;

	/*TODO Task C */


	return plaintext_len;
}


/*
 * Generates a CMAC
 */
void
gen_cmac(unsigned char *data, size_t data_len, unsigned char *key, 
    unsigned char *cmac, int bit_mode)
{

	/* TODO Task D */

}


/*
 * Verifies a CMAC
 */
int
verify_cmac(unsigned char *cmac1, unsigned char *cmac2)
{
	int verify;

	verify = 0;

	/* TODO Task E */

	return verify;
}



/* TODO Develop your functions here... */

unsigned char* readText(char *path, unsigned long* data_len)
{
	unsigned char* data;
	FILE *fp;

	fp = fopen(path,"rb");

	fseek(fp, 0, SEEK_END);
	*data_len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	data = malloc(*data_len);

	if (data == 0)
	{
		if(fread(data, 1, *data_len, fp) != *data_len)
			exit(1);
	}

	fclose(fp);

	return data;
}

void writeText(char* path, unsigned char *data, unsigned long data_len)
{
	FILE *fp;

	fp = fopen(path, "wb");
	fwrite(data, 1, data_len, fp);
}

/*
 * Encrypts the input file and stores the ciphertext to the output file
 *
 * Decrypts the input file and stores the plaintext to the output file
 *
 * Encrypts and signs the input file and stores the ciphertext concatenated with 
 * the CMAC to the output file
 *
 * Decrypts and verifies the input file and stores the plaintext to the output
 * file
 */
int
main(int argc, char **argv)
{
	int opt;			/* used for command line arguments */
	int bit_mode;			/* defines the key-size 128 or 256 */
	int op_mode;			/* operation mode */
	char *input_file;		/* path to the input file */
	char *output_file;		/* path to the output file */
	unsigned char *password;	/* the user defined password */

	/* Init arguments */
	input_file = NULL;
	output_file = NULL;
	password = NULL;
	bit_mode = -1;
	op_mode = -1;

	//my variables
	
	unsigned char* input_data = NULL;  // input data like the name
	unsigned long input_len = 0;	   // length of input
	unsigned char* output_data = NULL; // output data 
	unsigned long output_len = 0;	   // length of output
	unsigned char key[256], iv[256];


	/*
	 * Get arguments
	 */
	while ((opt = getopt(argc, argv, "b:i:m:o:p:desvh:")) != -1) {
		switch (opt) {
		case 'b':
			bit_mode = atoi(optarg);
			break;
		case 'i':
			input_file = strdup(optarg);
			break;
		case 'o':
			output_file = strdup(optarg);
			break;
		case 'p':
			password = (unsigned char *)strdup(optarg);
			break;
		case 'd':
			/* if op_mode == 1 the tool decrypts */
			op_mode = 1;
			break;
		case 'e':
			/* if op_mode == 1 the tool encrypts */
			op_mode = 0;
			break;
		case 's':
			/* if op_mode == 1 the tool signs */
			op_mode = 2;
			break;
		case 'v':
			/* if op_mode == 1 the tool verifies */
			op_mode = 3;
			break;
		case 'h':
		default:
			usage();
		}
	}


	/* check arguments */
	check_args(input_file, output_file, password, bit_mode, op_mode);

	/* TODO Develop the logic of your tool here... */

	if (input_file != NULL)
	{
		input_data = readText(input_file, &input_len);
	}

	/* Initialize the library */

	/* Keygen from password */

	keygen(password, key, iv, bit_mode);
	/* Operate on the data according to the mode */
	switch(op_mode)
	{
		/* encrypt */
		case 0: 
				output_len = input_len - (input_len % BLOCK_SIZE) + BLOCK_SIZE;
				output_data  = malloc(output_len);

				encrypt(input_data, input_len, key, iv, output_data, bit_mode);
				break;

		/* decrypt */
		case 1: 
				output_data = malloc(input_len);
				output_len = decrypt(input_data, input_len, key, iv, output_data, bit_mode);
				break;

		default:
				break;
	}

	if(output_len)
	{
		writeText(output_file, output_data, output_len);
	}


	/* sign */

	/* verify */
		
	/* Clean up */
	free(input_file);
	free(output_file);
	free(password);
	free(input_data);
	free(output_data);


	/* END */
	return 0;
}
