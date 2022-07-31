# 3 sign the  generated certificate req for https://onlineup.web.app
openssl ca -config openssl.cnf -policy policy_anything \
           -md sha256 -days 3650 \
           -in server.csr -out server.crt -batch \
           -cert ca.crt -keyfile ca.key
