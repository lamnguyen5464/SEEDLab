echo "Private key extracted from certificate: "
openssl asn1parse -i -in c0.pem -strparse 4 -out c0_body.bin -noout && sha256sum c0_body.bin

