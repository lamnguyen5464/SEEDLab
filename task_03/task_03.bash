head -c 54 pic_original.bmp  > header

openssl enc  -aes-128-cbc  -e -in pic_original.bmp -out raw_encrypted_pic.bmp -K 00112233445566778889aabbccddeeff -iv 0102030405060708
tail -c +55 raw_encrypted_pic.bmp > body
cat header body > encrypted_pic_cbc.bmp

openssl enc  -aes-128-ecb  -e -in pic_original.bmp -out raw_encrypted_pic.bmp -K 00112233445566778889aabbccddeeff 
tail -c +55 raw_encrypted_pic.bmp > body
cat header body > encrypted_pic_ecb.bmp
