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

**EBC mode:**  only processes single blocks at once and it don't use initialization vector in the encrytion process. As a result, the encrypted output is exactly the same if any underlying block is identical to another.

**CBC (cipher-block chaining) mode:**  initialization vector must be used prior to starting the encryption and it is considered to be the password,  it is initially hashed for a 256-bit output, followed by AES encryption for a 512-bit output, 256-bits for the following vector, and a 256-bit encrypted output. The following 256 bits are then encrypted using that vector. The chaining process keeps going till the file's end.



### Task 4
1. ECB and CBC use padding in encryption while CFB and OFB, because:
	- While encrypting, ECB and CBC work with fixed-size block of data so if the data size is not enough to match the block size, it need to use padding.
	- use XOR key use this to XOR the original message so it can work with any size of data and generate the cipher text with the same size of the plain text. As a result, it don't need padding in encryption progress.

2.First of all, we create 3 file with different size:
```
echo "----------[Start Task 04]----------"
rm -rf *.txt
echo "Create 3 files..."
echo -n "abcde" > f1.txt # 5 bytes
echo -n "123456789A" > f2.txt # 10 bytes
echo -n "0123456789ABCDEF" > f3.txt # 16 bytes
echo "Info of these file:"
```
And this are a list of modes for encryption and list of file besides the fixed key and iv:

```
ls -l
files=("f1.txt" "f2.txt" "f3.txt")
modes=("-aes-128-cbc" "-aes-128-cfb" "-aes-128-ecb" "-aes-128-ofb" )
key=00112233445566778889aabbccddeeff
iv=0102030405060708
```
Finally, a nested loop is conducted to encrypt each file with each mode and print the result to the output:
```
for cipherType in "${modes[@]}"
do
	echo "Start with mode $cipherType..."
	for file in "${files[@]}"
	do 
		encrypted_file="encrypted"$cipherType"-${file}"
		decrypted_file="decrypted"$cipherType"-${file}"
		openssl enc "$cipherType" -e -in "$file" -out "$encrypted_file" -K $key -iv $iv

		openssl enc "$cipherType" -d -in "$encrypted_file" -out "$decrypted_file" -K $key -iv $iv  -nopad

		echo "origin file:"
		xxd "$file"
		echo "decrypted file:"
		xxd "$decrypted_file"
		echo

	done 
done

echo "=> OFB, CFB do not have padding"

ls -l

echo "----------[End Task 04]----------"

```
The result of our process:
```
----------[Start Task 04]----------
Create 3 files...
Info of these file:
total 20
-rw-rw-r-- 1 seed seed   5 Jul 16 04:04 f1.txt
-rw-rw-r-- 1 seed seed  10 Jul 16 04:04 f2.txt
-rw-rw-r-- 1 seed seed  16 Jul 16 04:04 f3.txt
-rw-rw-r-- 1 seed seed  74 Jul 16 04:04 output.out
-rw-rw-r-- 1 seed seed 984 Jul 16 04:04 task_04.bash
Start with mode -aes-128-cbc...
origin file:
00000000: 6162 6364 65                             abcde
decrypted file:
00000000: 6162 6364 650b 0b0b 0b0b 0b0b 0b0b 0b0b  abcde...........

origin file:
00000000: 3132 3334 3536 3738 3941                 123456789A
decrypted file:
00000000: 3132 3334 3536 3738 3941 0606 0606 0606  123456789A......

origin file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF
decrypted file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF
00000010: 1010 1010 1010 1010 1010 1010 1010 1010  ................

Start with mode -aes-128-cfb...
origin file:
00000000: 6162 6364 65                             abcde
decrypted file:
00000000: 6162 6364 65                             abcde

origin file:
00000000: 3132 3334 3536 3738 3941                 123456789A
decrypted file:
00000000: 3132 3334 3536 3738 3941                 123456789A

origin file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF
decrypted file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF

Start with mode -aes-128-ecb...
origin file:
00000000: 6162 6364 65                             abcde
decrypted file:
00000000: 6162 6364 650b 0b0b 0b0b 0b0b 0b0b 0b0b  abcde...........

origin file:
00000000: 3132 3334 3536 3738 3941                 123456789A
decrypted file:
00000000: 3132 3334 3536 3738 3941 0606 0606 0606  123456789A......

origin file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF
decrypted file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF
00000010: 1010 1010 1010 1010 1010 1010 1010 1010  ................

Start with mode -aes-128-ofb...
origin file:
00000000: 6162 6364 65                             abcde
decrypted file:
00000000: 6162 6364 65                             abcde

origin file:
00000000: 3132 3334 3536 3738 3941                 123456789A
decrypted file:
00000000: 3132 3334 3536 3738 3941                 123456789A

origin file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF
decrypted file:
00000000: 3031 3233 3435 3637 3839 4142 4344 4546  0123456789ABCDEF

=> OFB, CFB do not have padding
total 116
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 decrypted-aes-128-cbc-f1.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 decrypted-aes-128-cbc-f2.txt
-rw-rw-r-- 1 seed seed   32 Jul 16 04:04 decrypted-aes-128-cbc-f3.txt
-rw-rw-r-- 1 seed seed    5 Jul 16 04:04 decrypted-aes-128-cfb-f1.txt
-rw-rw-r-- 1 seed seed   10 Jul 16 04:04 decrypted-aes-128-cfb-f2.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 decrypted-aes-128-cfb-f3.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 decrypted-aes-128-ecb-f1.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 decrypted-aes-128-ecb-f2.txt
-rw-rw-r-- 1 seed seed   32 Jul 16 04:04 decrypted-aes-128-ecb-f3.txt
-rw-rw-r-- 1 seed seed    5 Jul 16 04:04 decrypted-aes-128-ofb-f1.txt
-rw-rw-r-- 1 seed seed   10 Jul 16 04:04 decrypted-aes-128-ofb-f2.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 decrypted-aes-128-ofb-f3.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 encrypted-aes-128-cbc-f1.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 encrypted-aes-128-cbc-f2.txt
-rw-rw-r-- 1 seed seed   32 Jul 16 04:04 encrypted-aes-128-cbc-f3.txt
-rw-rw-r-- 1 seed seed    5 Jul 16 04:04 encrypted-aes-128-cfb-f1.txt
-rw-rw-r-- 1 seed seed   10 Jul 16 04:04 encrypted-aes-128-cfb-f2.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 encrypted-aes-128-cfb-f3.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 encrypted-aes-128-ecb-f1.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 encrypted-aes-128-ecb-f2.txt
-rw-rw-r-- 1 seed seed   32 Jul 16 04:04 encrypted-aes-128-ecb-f3.txt
-rw-rw-r-- 1 seed seed    5 Jul 16 04:04 encrypted-aes-128-ofb-f1.txt
-rw-rw-r-- 1 seed seed   10 Jul 16 04:04 encrypted-aes-128-ofb-f2.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 encrypted-aes-128-ofb-f3.txt
-rw-rw-r-- 1 seed seed    5 Jul 16 04:04 f1.txt
-rw-rw-r-- 1 seed seed   10 Jul 16 04:04 f2.txt
-rw-rw-r-- 1 seed seed   16 Jul 16 04:04 f3.txt
-rw-rw-r-- 1 seed seed 2514 Jul 16 04:04 output.out
-rw-rw-r-- 1 seed seed  984 Jul 16 04:04 task_04.bash
----------[End Task 04]----------

```
Through observation, with ECB and CBC mode encryption, the encrypted files of file 1 and file 2 are padding until each reach 16 and file 3 is padding until it reach 32. As a result, we can conclude that the size of the files change through encryption with ECB and CBC mode while does not change through OFB, CFB.
So it once more time assert that just ECB and CBC need padding.


### Task 5
First we encrypt the plain text with several modes:
```

file=file.txt
modes=("-aes-128-cbc" "-aes-128-cfb" "-aes-128-ecb" "-aes-128-ofb" )
key=00112233445566778889aabbccddeeff
iv=0102030405060708


for cipherType in "${modes[@]}"
do
	encrypted_file="encrypted"$cipherType"-${file}"
	decrypted_file="decrypted"$cipherType"-${file}"
	openssl enc "$cipherType" -e -in "$file" -out "$encrypted_file" -K $key -iv $iv

	# openssl enc "$cipherType" -d -in "$encrypted_file" -out "$decrypted_file" -K $key -iv $iv
done

```
After that, we make the corruption by using the tool to change the 55th bit to 00
<img src="https://user-images.githubusercontent.com/63250081/179359028-af04d063-986b-4b00-89d0-35a69752e186.png"/>


### Task 6


