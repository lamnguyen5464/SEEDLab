file=file.txt
modes=("-aes-128-cbc" "-aes-128-cfb" "-aes-128-ecb" "-aes-128-ofb" )
key=00112233445566778889aabbccddeeff
iv=0102030405060708


for cipherType in "${modes[@]}"
do
	encrypted_file="encrypted"$cipherType"-${file}"
	decrypted_file="decrypted"$cipherType"-${file}"

	openssl enc "$cipherType" -d -in "$encrypted_file" -out "$decrypted_file" -K $key -iv $iv
done


