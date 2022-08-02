# 3 sign the  generated certificate req for www.nguyen2022.com
openssl ca -config openssl.cnf -policy policy_anything \
           -md sha256 -days 3650 \
           -in server.csr -out server.crt -batch \
           -cert ca.crt -keyfile ca.key
