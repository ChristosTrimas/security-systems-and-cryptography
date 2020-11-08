#include "rsa.h"
#include "utils.h"

/*
 * Sieve of Eratosthenes Algorithm
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 * arg0: A limit
 * arg1: The size of the generated primes list. Empty argument used as ret val
 *
 * ret:  The prime numbers that are less or equal to the limit
 */
size_t* sieve_of_eratosthenes(int limit, int *primes_sz)
{
	size_t primes[];
	size_t *prime = malloc(sizeof((size_t)*limit)+1);
	size_t i,j,k=2;
	/* TODO */	

	for(i = 2; i <= n; i ++)
		prime[i] = i;

	for(i = 2; i*i <= n; i ++)
		for(j = i*i; j <= n; j += i)
			prime[j] = 0;

	for(i = 2; i <= n; i ++)
	{
		for (k=0; k < limit; k++)
		{
			if(prime[i] != 0)
			{
				printf("%d ",prime[i]);
				primes[k] = prime[i];
			}
		}
	}

	return primes;
}


/*
 * Greatest Common Denominator
 *
 * arg0: first number
 * arg1: second number
 *
 * ret: the GCD
 */
int gcd(int a, int b)
{

	/* TODO */
	int tmp;

	while(a != 0)
	{
		tmp = a;
		a = b % a;
		b = tmp;
	}

	return b;

}

// extra function No.1

size_t compute_n(size_t p, size_t q)
{
	return p * q;
}

// extra function No.2

size_t calc_fi_n(size_t p, size_t q)
{
	return (p-1)*(q-1);
}


/*
 * Chooses 'e' where 
 *     1 < e < fi(n) AND gcd(e, fi(n)) == 1
 *
 * arg0: fi(n)
 *
 * ret: 'e'
 */
size_t choose_e(size_t fi_n)
{
	size_t e, fi, n;
	/* TODO */
	size_t *prime = sieve_of_eratosthenes(RSA_SIEVE_LIMIT, NULL); //might delete the second arg later

	while(1)
	{
		e = prime[rand()%sizeof(prime)];
		size_t p = prime[rand()%sizeof(prime)];
		size_t q = prime[rand()%sizeof(prime)];

		if(p == 1 || q == 1)
			continue;

		fi = calc_fi_n(p ,q);

		if( 1 < e && e < fi && gcd(e, fi) == 1 && e%fi != 0 && compute_n(p,q) > 123)
		{
			fi_n = fi;
			n = compute_n(p,q)
			return e;
		}
	}

}

// extra function No.3

size_t gcdExtended(int a, int b, int* x, int* y) //geeks for geeks found 
{ 
    // Base Case 
    if (a == 0) { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b % a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
/*
 * Calculates the modular inverse
 *
 * arg0: first number
 * arg1: second number
 *
 * ret: modular inverse
 */
size_t
mod_inverse(size_t e, size_t fi) // changed var names from a,b to e,fi respectively
{

	/* TODO */
	size_t x, y, g = gcdextended(a, b, b&x, &y);

	if(g != 1)
		return -1;
	if ((a*x) % b == 1)
		return x;
	if ((a*y) % b == 1)
		return y;
}


/*
 * Generates an RSA key pair and saves
 * each key in a different file
 */
void
rsa_keygen(void)
{
	size_t p;
	size_t q;
	size_t n;
	size_t fi_n;
	size_t e;
	size_t d;

	/* TODO */

}


/*
 * Encrypts an input file and dumps the ciphertext into an output file
 *
 * arg0: path to input file
 * arg1: path to output file
 * arg2: path to key file
 */
void
rsa_encrypt(char *input_file, char *output_file, char *key_file)
{

	/* TODO */

}


/*
 * Decrypts an input file and dumps the plaintext into an output file
 *
 * arg0: path to input file
 * arg1: path to output file
 * arg2: path to key file
 */
void
rsa_decrypt(char *input_file, char *output_file, char *key_file)
{

	/* TODO */

}
