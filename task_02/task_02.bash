openssl enc  -aes-128-cbc  -e -in plaintext.txt -out cbc_cipher.bin -K 00112233445566778889aabbccddeeff -iv 0102030405060708

#decrypt
openssl enc  -aes-128-cbc  -d -in cbc_cipher.bin -out cbc_plain.txt \
-K 00112233445566778889aabbccddeeff \
-iv 0102030405060708

#valid
diff plaintext.txt cbc_plain.txt
