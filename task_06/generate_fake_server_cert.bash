openssl req -newkey rsa:2048 -sha256  \
        -keyout fake_server.key   -out fake_server.csr  \
        -subj "/CN=www.fake_nguyen2022.com/O=FakeNguyen2022 Inc./C=US" \
        -passout pass:123456

