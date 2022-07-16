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

### Overview Result of 6 tasks


### Task 1

First of all, we run the freq.py file to get the frequency analysis of the cipher text with single-letter frequencies,
bigram frequencies (2-letter sequence), and trigram frequencies (3-letter sequence)

```
-------------------------------------
1-gram (top 26):
n: 488
y: 373
v: 348
x: 291
u: 280
q: 276
m: 264
h: 235
t: 183
i: 166
p: 156
a: 116
c: 104
z: 95
l: 90
g: 83
b: 83
r: 82
e: 76
d: 59
f: 49
s: 19
k: 5
j: 5
o: 4
w: 1
-------------------------------------
2-gram (top 26):
yt: 115
tn: 89
mu: 74
nh: 58
vh: 57
hn: 57
vu: 56
nq: 53
xu: 52
up: 46
xh: 45
yn: 44
np: 44
vy: 44
nu: 42
qy: 39
vq: 33
vi: 32
gn: 32
av: 31
my: 31
xz: 30
ym: 30
yx: 29
mq: 27
tv: 27
-------------------------------------
3-gram (top 26):
ytn: 78
vup: 30
mur: 20
ynh: 18
xzy: 16
mxu: 14
gnq: 14
ytv: 13
nqy: 13
vii: 13
bxh: 13
lvq: 12
nuy: 12
vyn: 12
uvy: 11
lmu: 11
nvh: 11
cmu: 11
tmq: 10
vhp: 10
vym: 10
ymx: 10
nhn: 10
tvy: 10
yxh: 10
yzh: 9

```
According to this result, we can infer the descending order of the single letter's frequency and we can consider this string to be the key for decryption
```
nyvxuqmhtipaczlgbredfskjow
```
Besides, we have the frequency of single letter in english with the descending order:
```
eothasinrdluymwfgcbpkvjqxz
```
Then, with the key and the frequency string of english letter, we create a bash script to conduct the replacement of the cipher text's letter correspoding to the english letter have the same index in the 2 strings of frequency analysis. Finally we are able to achieve the final plain text.

### Task 2
Firstly, we create a plain text: "This is the secret content!!!"
```
echo "----------[Start Task 02]----------"


modes=("-aes-128-cbc" "-bf-cbc" "-aes-128-cfb" "-aes-128-ecb")

for cipherType in "${modes[@]}"
do

	echo "# Start using mode $cipherType"
	echo "Plaintext before encrypt:"
	cat plaintext.txt
	echo


	echo "Encypt with mode: $cipherType"
	openssl enc "$cipherType" -e -in plaintext.txt -out ciphertext.txt -K 00112233445566778889aabbccddeeff -iv 0102030405060708

	echo "Ciphertext after encrypt:"
	cat ciphertext.txt
	echo 
	echo

	echo "Decrypt with mode: $cipherType"
	openssl enc "$cipherType" -d -in ciphertext.txt -out decryptedtext.txt -K 00112233445566778889aabbccddeeff -iv 0102030405060708


	echo "Ciphertext after decrypt:"
	cat decryptedtext.txt
	echo


	echo "Diff of plaintext.txt and ciphertext.txt:"
	diff plaintext.txt decryptedtext.txt
	echo
	echo
	echo

done

echo "----------[End Task 02]----------"
```
In the bash script we have create a list of modes for encryption: "-aes-128-cbc" "-bf-cbc" "-aes-128-cfb" "-aes-128-ecb"
Then, with each mode the encryption is conducted with the openssl enc command and the result is printed to the output through a loop.
In addition, we decrypt the encrypted text and observe that the result is similar to the original plain text.
Here is the final result:
```
----------[Start Task 02]----------
# Start using mode -aes-128-cbc
Plaintext before encrypt:
This is the secret content!!!

Encypt with mode: -aes-128-cbc
Ciphertext after encrypt:
������8��ȳfS�9F]!����Ka�<x��

Decrypt with mode: -aes-128-cbc
Ciphertext after decrypt:
This is the secret content!!!

Diff of plaintext.txt and ciphertext.txt:



# Start using mode -bf-cbc
Plaintext before encrypt:
This is the secret content!!!

Encypt with mode: -bf-cbc
Ciphertext after encrypt:
��򞆘`����;��B�7�f��!�8��

Decrypt with mode: -bf-cbc
Ciphertext after decrypt:
This is the secret content!!!

Diff of plaintext.txt and ciphertext.txt:



# Start using mode -aes-128-cfb
Plaintext before encrypt:
This is the secret content!!!

Encypt with mode: -aes-128-cfb
Ciphertext after encrypt:
���V�V�����=u?g@�{��̛'�L.

Decrypt with mode: -aes-128-cfb
Ciphertext after decrypt:
This is the secret content!!!

Diff of plaintext.txt and ciphertext.txt:



# Start using mode -aes-128-ecb
Plaintext before encrypt:
This is the secret content!!!

Encypt with mode: -aes-128-ecb
Ciphertext after encrypt:
���JI�|!��o���mːҖ���8���;�

Decrypt with mode: -aes-128-ecb
Ciphertext after decrypt:
This is the secret content!!!

Diff of plaintext.txt and ciphertext.txt:



----------[End Task 02]----------

```



### Task 3
The original picture:

<img  src="https://user-images.githubusercontent.com/63250081/179357050-a13be19f-ce96-424c-b809-f5cd61a63c6b.jpg"/>




The bash script to solve this problem:
```
head -c 54 pic_original.bmp  > header

openssl enc  -aes-128-cbc  -e -in pic_original.bmp -out raw_encrypted_pic.bmp -K 00112233445566778889aabbccddeeff -iv 0102030405060708
tail -c +55 raw_encrypted_pic.bmp > body
cat header body > encrypted_pic_cbc.bmp

openssl enc  -aes-128-ecb  -e -in pic_original.bmp -out raw_encrypted_pic.bmp -K 00112233445566778889aabbccddeeff 
tail -c +55 raw_encrypted_pic.bmp > body
cat header body > encrypted_pic_ecb.bmp

```
Because the first 54 bits s contain the header information about the picture, we store it to a varibale "head".
With each mode, we encrypt the original picture, through encryption, the header is changed so it is not anymore correctly, to solve this problem, we cat the bits from offset 55 to the end of the file with the orginal 54 bits header to achive the correct encrypted picture.

The result of encryption in ECB mode

<img  src="https://user-images.githubusercontent.com/63250081/179357432-578b9b3e-bc7b-4e9e-af55-733b7fd7a6f9.jpg"/>

The result of encryption in CBC mode

<img  src="https://user-images.githubusercontent.com/63250081/179357462-63af2967-3487-4c48-9469-84ba3083a869.jpg"/>

Through observation, in the result of ECB, we can still recognize the shape, some details of the original picutre while the result of CBC mode does not contain any information of the original picture.
The reason is:

EBC mode:  only processes single blocks at once and it don't use initialization vector in the encrytion process. As a result, the encrypted output is exactly the same if any underlying block is identical to another.

CBC (cipher-block chaining) mode:  initialization vector must be used prior to starting the encryption and it is considered to be the password,  it is initially hashed for a 256-bit output, followed by AES encryption for a 512-bit output, 256-bits for the following vector, and a 256-bit encrypted output. The following 256 bits are then encrypted using that vector. The chaining process keeps going till the file's end.



### Task 4

To generate a signature, it is neccessary to have variables with the values of the public and private key

```cpp
	BIGNUM* d = BN_new();	// private key
	BIGNUM* e = BN_new();	// public key
	BIGNUM* n = BN_new();

	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
```

The next step is to encode the message to hex string

```cpp
	BIGNUM* rawValue = BN_new();
	BN_hex2bn(&rawValue, "49206f776520796f7520323530302e"); // after encoding: I owe you 2500.
```

With the encoded message, we use the function encryptRSA to generate the signed message
</br> The different point of generating signature compared to normal encryption is that generating signature use private key to encrypt and public key to decrypt while normal encryption use public key for encrypting and decrypting.
</br> Which mean the sender just need to give the receiver the public key to extract the signed message, but this message must be encrypt by the private key. If not, the decryption with the public key will give the wrong answer.

```cpp
	BIGNUM* rawValue = BN_new();
	BN_hex2bn(&rawValue, "49206f776520796f7520323530302e"); // after encoding: I owe you 2500.

	BIGNUM* signedValue = encryptRSA(rawValue, d, n); // sign: use private key to encypt
	printBN("[Task 4] signed value: ", signedValue);
	BIGNUM* unsignedValue = decryptRSA(signedValue, e, n); // extract signed value: use public key to decrypt

	printBN("[Task 4] unsigned value: ", unsignedValue);

	printf("[Task 4] Origin text: ");
	printHX(BN_bn2hex(unsignedValue));
```

Here we use the encoded value to generate signature and use public key to decrypt this value combined with API _BN_bn2hex_ to archive the original message:

```
[Task 4] signed value:  0B327F9EF80760C3136DB55C90E963429290E31ECC7D3975398263269F2965C8
[Task 4] unsigned value:  49206F776520796F7520323530302E
[Task 4] Origin text: I owe you 2500.
```

### Task 5

First of all, we assign the raw value and the public key to variables:

```cpp
	BIGNUM* rawValue = BN_new();
	BIGNUM* signedValue = BN_new();
	BIGNUM* e = BN_new();
	BIGNUM* n = BN_new();
	BN_hex2bn(&rawValue, "4c61756e63682061206d6973736c652e");	// after encoding: Launch a missile.
	BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&signedValue, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
```

Then we use the public key and the decrypt RSA method with the function created in the previous task to verify the sign:

```cpp
	BIGNUM* decryptedValue = decryptRSA(signedValue, e, n);
	printf("[Task 5] extracted sign: ");
	printHX(BN_bn2hex(decryptedValue));
```

And we have the decrypted value:

```
[Task 5] extracted sign: Launch a missile.
```

Through observation, the extracted sign is similar to the original message Alice sent to Bob => the signature is Alice's.

So, now we change the last 2 byte of the signed value from 2F to 3F then repeat the verify process.

```cpp
	BN_hex2bn(&signedValue, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
	BIGNUM* redecryptedValue = decryptRSA(signedValue, e, n);
	printf("[Task 5] corrupted text:\n");
	printHX(BN_bn2hex(redecryptedValue)); // corrupted value
```

We receive a corrupted value as following:

```
[Task 5] corrupted text:
��,O�c��rm=f�:N�����
```

So, it's not the message Alice sent to Bob according to the modification of the signed value.

In conclusion, unless the message is correctly signed with the sender's private key, it will be impossible to extract the right message through the verification process.

### Task 6

After following the steps in the requirement to download the certificate, we need to extract the public key and the signed message from the downloaded certificate.
</br>We get the public key by:
</br>   **n**: run '_extract in openssl x509 -in c1.pem -text -noout_'
</br>   **e**: receive from the certificate x509
</br>   **signedValue**: run '_extract in openssl x509 -in c0.pem -text -noout_'

```cpp
	BN_CTX *ctx = BN_CTX_new();

	BIGNUM* e = BN_new();
	BIGNUM* d = BN_new();
	BIGNUM* n = BN_new();
	BIGNUM* signedValue = BN_new();

	// extract in openssl x509 -in c1.pem -text -noout
	BN_hex2bn(&n, "00c14bb3654770bcdd4f58dbec9cedc366e51f311354ad4a66461f2c0aec6407e52edcdcb90a20eddfe3c4d09e9aa97a1d8288e51156db1e9f58c251e72c340d2ed292e156cbf1795fb3bb87ca25037b9a52416610604f571349f0e8376783dfe7d34b674c2251a6df0e9910ed57517426e27dc7ca622e131b7f238825536fc13458008b84fff8bea75849227b96ada2889b15bca07cdfe951a8d5b0ed37e236b4824b62b5499aecc767d6e33ef5e3d6125e44f1bf71427d58840380b18101faf9ca32bbb48e278727c52b74d4a8d697dec364f9cace53a256bc78178e490329aefb494fa415b9cef25c19576d6b79a72ba2272013b5d03d40d321300793ea99f5");
	BN_hex2bn(&e, "010001");
	// extract in openssl x509 -in c0.pem -text -noout
	BN_hex2bn(&signedValue, "aa9fbe5d911bade44e4ecc8f07644435b4ad3b133fc129d8b4abf3425149463bd6cf1e4183e10b572f83697965076f59038c51948918103e1e5cedba3d8e4f1a1492d32bffd498cba7930ebcb71b93a4424246d9e5b11a6b682a9b2e48a92f1d2ab0e3f820945481502eeed7e0207a7b2e67fbfad817a45bdcca0062ef23af7a58f07a740cbd4d43f18c0287dce3ae09d2f7fa373cd24bab04e543a5d255110e41875f38a8e57a5e4c46b8b6fa3fc34bcd4035ffe0a471740ac1208be3544784d518bd519b405ddd423012d13aa5639aaf9008d61bd1710b067190ebaeadafba5fc7db6b1e78a2b4d10623a763f3b543fa568c50177b1c1b4e106b220e845294");
```

Then, we use our decryptRSA function to extract the signedValue variable to archive the decrypted message then mod 2^256 to have the private key. Finally, we compare that key with the key extracted from the certificate archived by running '_bash key.bash_'

```cpp
	BIGNUM* decryptedValue = decryptRSA(signedValue, e, n);
	BIGNUM* mod = BN_new();
	BIGNUM* num_2 = BN_new();
	BIGNUM* num_256 = BN_new();
	BN_dec2bn(&num_2, "2");
	BN_dec2bn(&num_256, "256");

	BN_exp(mod, num_2, num_256, ctx);
	BN_mod(d, decryptedValue, mod, ctx);
	printBN("[Task 6] private key: ", d);	// then compare with private key after run key.bash
```

The final result:

```
[Task 6] private key:  7061DF0A50B8F2BA3367ECFABAB273A16F3BB1378DBE1FE524E6DFD90DFA3B91
Private key extracted from certificate:
7061df0a50b8f2ba3367ecfabab273a16f3bb1378dbe1fe524e6dfd90dfa3b91  c0_body.bin
```
