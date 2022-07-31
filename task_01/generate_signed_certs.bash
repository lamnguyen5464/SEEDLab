# 2 generate self-signed certificate
openssl req -x509 -newkey rsa:4096 -sha256 -days 3650 \
	-keyout ca.key -out ca.crt  \
	-passout pass:123456 \
	-config openssl.cnf
