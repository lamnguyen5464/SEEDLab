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

### Task 2

### Task 3

### Task 4

### Task 5

### Task 6
