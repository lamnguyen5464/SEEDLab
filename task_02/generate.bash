# 2 generate certificate req for https://onlineup.web.app/welcome 
openssl req -newkey rsa:2048 -sha256  \
	-keyout server.key   -out server.csr  \
	-subj "/CN=www.onlineup.web.app/O=Bank32 Inc./C=US" \
	-passout pass:123456
