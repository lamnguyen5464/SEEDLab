#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>

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

BIGNUM* encryptRSA(BIGNUM* rawValue, BIGNUM* encryptKey, BIGNUM* n) {
	/*
	 * e(x) = (x ^ e) mod n
	*/
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* cipherValue = BN_new();
	BN_mod_exp(cipherValue, rawValue, encryptKey, n, ctx);
	BN_CTX_free(ctx);
	return cipherValue;
}

BIGNUM* decryptRSA(BIGNUM* cipherValue, BIGNUM* decryptKey, BIGNUM* n)
{
	/*
	 * d(x) = (x ^ d) mod n
	*/
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* rawValue = BN_new();
	BN_mod_exp(rawValue, cipherValue, decryptKey, n, ctx);
	BN_CTX_free(ctx);
	return rawValue;
}


void printBN(char *tag, BIGNUM * a) {
	char * str = BN_bn2hex(a);
   	printf("%s %s\n", tag, str);
   	OPENSSL_free(str);
}

int hex_to_int(char c) {
    if (c >= 97)
        c = c - 32;
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first * 10 + second;
    if (result > 9) result--;
    return result;
}

int hex_to_ascii(const char c, const char d)
{
	int high = hex_to_int(c) * 16;
	int low = hex_to_int(d);
	return high + low;
}

void printHX(const char* hexStr)
{
	int length = strlen(hexStr);
	if (length % 2 != 0) {
		return;
	}
	int i;
	char buf = 0;
	for(i = 0; i < length; i++) {
		if(i % 2 != 0)
			printf("%c", hex_to_ascii(buf, hexStr[i]));
		else
		    buf = hexStr[i];
	}
	printf("\n");
}

void task1() {
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();

	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	BN_hex2bn(&e, "0D88C3");

	BIGNUM* phi = getPhiOf(p,q);
	BIGNUM* d = getModuloInverseOf(e, phi);

	printBN("[Task 1] The private key is", d);
	printf("\n");

}

void task2() {
	BIGNUM* n = BN_new();	// n = p * q
	BIGNUM* d = BN_new();	// private key
	BIGNUM* message = BN_new();
	BIGNUM* e = BN_new();	// public key

	BN_hex2bn(&message, "4120746f702073656372657421"); // after encoding
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	BIGNUM* cipherValue = encryptRSA(message, e, n);


	printBN("[Task 2] encypted text: ", cipherValue);

	BIGNUM* rawValue = decryptRSA(cipherValue, d, n);

	printBN("[Task 2] decypted text: ", rawValue);

	if (BN_cmp(rawValue, message) == 0) {
		printf("[Task 2] Decypted text == Original text\n");
	}
	printf("\n");

}

void task3() {
	BIGNUM *cipherValue;
	BIGNUM* d = BN_new();	// private key
	BIGNUM* e = BN_new();	// public key
	BIGNUM* n = BN_new();

	BN_hex2bn(&cipherValue, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");


	BIGNUM* rawValue = decryptRSA(cipherValue, d, n);

	printBN("[Task 3] decypted value: ", rawValue);

	printf("[Task 3] raw text: ");
	printHX(BN_bn2hex(rawValue));
	printf("\n");
}

void task4() {
	BIGNUM* d = BN_new();	// private key
	BIGNUM* e = BN_new();	// public key
	BIGNUM* n = BN_new();

	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	BIGNUM* rawValue = BN_new();
	BN_hex2bn(&rawValue, "49206f776520796f7520323530302e"); // after encoding: I owe you 2500.

	BIGNUM* signedValue = encryptRSA(rawValue, d, n); // sign: use private key to encypt
	printBN("[Task 4] signed value: ", signedValue);
	BIGNUM* unsignedValue = decryptRSA(signedValue, e, n); // extract signed value: use public key to decrypt

	printBN("[Task 4] unsigned value: ", unsignedValue);

	printf("[Task 4] Origin text: ");
	printHX(BN_bn2hex(unsignedValue));
	printf("\n");
}

void task5() {
	BIGNUM* rawValue = BN_new();
	BIGNUM* signedValue = BN_new();
	BIGNUM* e = BN_new();
	BIGNUM* n = BN_new();
	BN_hex2bn(&rawValue, "4c61756e63682061206d6973736c652e");	// after encoding: Launch a missile.
	BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&signedValue, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");

	// verify signedValue
	BIGNUM* decryptedValue = decryptRSA(signedValue, e, n);
	printf("[Task 5] extracted sign: ");
	printHX(BN_bn2hex(decryptedValue));


	// change last byte from 2F -> 3F
	BN_hex2bn(&signedValue, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
	BIGNUM* redecryptedValue = decryptRSA(signedValue, e, n);
	printf("[Task 5] re-decrypted text: ");
	printHX(BN_bn2hex(redecryptedValue)); // corrupted value

	printf("\n");

}

int main () {
	task1();
	task2();
	task3();
	task4();
	task5();
  	return 0;
}
