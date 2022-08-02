# 2 generate certificate req for www.nguyen2022.com
openssl req -newkey rsa:2048 -sha256  \
	-keyout server.key   -out server.csr  \
	-subj "/CN=www.nguyen2022.com/O=Bank32 Inc./C=US" \
	-passout pass:123456
