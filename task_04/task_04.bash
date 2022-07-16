echo "----------[Start Task 04]----------"
rm -rf *.txt
echo "Create 3 files..."
echo -n "abcde" > f1.txt # 5 bytes
echo -n "123456789A" > f2.txt # 10 bytes
echo -n "0123456789ABCDEF" > f3.txt # 16 bytes
echo "Info of these file:"
ls -l
files=("f1.txt" "f2.txt" "f3.txt")
modes=("-aes-128-cbc" "-aes-128-cfb" "-aes-128-ecb" "-aes-128-ofb" )
key=00112233445566778889aabbccddeeff
iv=0102030405060708


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
