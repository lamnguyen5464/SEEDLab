# SEEDLab

```
Nguyen Truong Lam - 19125101
Bui Quang Huy - 19125047
```

## Instruction

Run:

```
bash run.bash
```

## Report

### Task 1

First of all, we initialize 3 variables of p,q and e with the values given in the problem

```
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();

	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	BN_hex2bn(&e, "0D88C3");

```

The next step is to calculate phi n with n = p\*q through the function:

```

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

```

Finally, we have the theory:

# e\*d = 1 (mod phi[n]) => d is inverse modulo of e with mod phi[n];

So, the solution of this problem is the inverse modulo of the big num e computed by the function

```
BIGNUM* getModuloInverseOf(BIGNUM* e, BIGNUM* mod) {
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* res = BN_new();
	BN_mod_inverse(res, e, mod, ctx);
	BN_CTX_free(ctx);
	return res;
}

```

### Task 2

### Task 3

### Task 4

### Task 5

### Task 6
