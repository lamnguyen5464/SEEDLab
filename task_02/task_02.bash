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
