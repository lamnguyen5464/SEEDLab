modes=("-aes-128-cbc" "-aes-128-cfb" "-aes-128-ecb" "-aes-128-ofb" )
file=file.txt
echo "Origin file: "
cat "$file"
echo
for cipherType in "${modes[@]}"
do
        decrypted_file="decrypted"$cipherType"-${file}"
	echo "$decrypted_file: "
	cat "$decrypted_file"
	cp "$decrypted_file" common_decrypted_file.txt
	python3 checkDiff.py
	echo

done


~                                                                               
~                                                                               
~            
