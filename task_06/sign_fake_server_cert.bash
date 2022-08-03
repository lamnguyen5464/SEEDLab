openssl ca -config openssl.cnf -policy policy_anything \
           -md sha256 -days 3650 \
           -in fake_server.csr -out fake_server.crt -batch \
           -cert ca.crt -keyfile ca.key
