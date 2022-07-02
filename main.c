#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a) {
	char * number_str = BN_bn2hex(a);
   	printf("%s %s\n", msg, number_str);
   	OPENSSL_free(number_str);
}


BIGNUM* getPhiOf(BIGNUM* p, BIGNUM* q) {
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* p_minus_one = BN_new();
	BIGNUM* q_minus_one = BN_new();
	BIGNUM* one = BN_new();
	BIGNUM* phi = BN_new();

	BN_dec2bn(&one, "1");
	BN_sub(p_minus_one, p, one);
	BN_sub(q_minus_one, q, one);
	BN_mul(phi, p_minus_one, q_minus_one, ctx);

	BN_CTX_free(ctx);

	return phi;
}


BIGNUM* getModuloInverseOf(BIGNUM* e, BIGNUM* mod) {
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* res = BN_new();
	BN_mod_inverse(res, e, mod, ctx);
	BN_CTX_free(ctx);
	return res;
}

void task1() {
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();

	// Assign the first large prime
	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");

	// Assign the second large prime
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");

	// Assign the Modulus
	BN_hex2bn(&e, "0D88C3");

	BIGNUM* phi = getPhiOf(p,q);
	BIGNUM* d = getModuloInverseOf(e, phi);

	printBN("[Task 1] The private key is", d);


}


int main () {
	task1();
  	return 0;
}
