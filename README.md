# SEEDLab

```
Nguyen Truong Lam - 19125101
Bui Quang Huy - 19125047
```

## Instruction

Run:

```
bash run.bash
```

## Report

### Overview Result of 6 tasks


### Task 1
Firstly, we have create bash script files containing the commands in the requirement of task 1, then run these scripts to obtain file ca.key contains the CA’s private key, and ca.crt contains the public-key certificate.
<img width="700" src="https://user-images.githubusercontent.com/63250081/182834509-5e18fc8d-b3d8-4de8-afdd-197d6ded4393.png"/>


Besides, the decode script creates the output.yaml file which contains the certificate. To answer the questions, we will seperate this output into different parts:


• What part of the certificate indicates this is a CA’s certificate?: the CA constraint
<img width="700" src="https://user-images.githubusercontent.com/63250081/182833614-f0bcc146-66f4-4a6a-90c4-789d9d7dc415.png"/>

• What part of the certificate indicates this is a self-signed certificate?: **Authority Key Identifier** and **Subject Key Identifier** 
```

X509v3 Subject Key Identifier: 
  3F:25:BE:9A:09:54:7B:02:AA:78:04:78:8F:F2:DF:10:17:DE:E2:51
X509v3 Authority Key Identifier: 
  keyid:3F:25:BE:9A:09:54:7B:02:AA:78:04:78:8F:F2:DF:10:17:DE:E2:51
```

• In the RSA algorithm, we have a public exponent e, a private exponent d, a modulus n, and two secret
numbers p and q, such that n = pq. Please identify the values for these elements in your certificate
and key files.

public exponent e:
```
publicExponent: 65537 (0x10001)
```

private exponent d:
```
privateExponent:
    78:77:e7:b0:23:85:b7:17:c0:27:98:b8:22:83:07:
    1f:f9:a1:19:41:b1:58:84:e0:f8:12:2b:87:c3:5b:
    b7:bb:73:1e:08:73:05:48:5f:12:92:f7:b1:09:71:
    7c:bc:fd:b5:2f:12:b1:c3:d1:fb:98:de:87:b3:e0:
    bf:b8:48:7b:5b:da:fe:3e:fe:b9:3e:2e:89:ee:6d:
    67:a0:10:31:e9:2d:71:89:ea:72:9a:52:88:bf:b7:
    fb:82:79:94:38:b6:67:4d:b5:a1:ab:ca:1f:8a:d7:
    bb:c6:89:bb:f4:87:91:3b:34:ec:05:47:88:dd:89:
    cb:94:d0:9c:29:cb:d5:7c:aa:73:43:c0:56:9e:5e:
    8c:7b:f6:8b:af:50:c1:28:b7:2b:40:f8:7d:c5:1b:
    01:ea:76:6f:3e:c2:dc:4e:7e:3a:d2:58:7d:b5:e4:
    3b:62:c2:fb:f5:9f:c7:c1:dd:ae:ce:e7:ae:d1:a4:
    b0:c3:3d:e4:0b:4e:4f:0c:8b:6a:fd:a6:b1:1a:a1:
    70:bc:ff:72:40:c4:a4:e0:02:b4:3c:f1:47:20:b0:
    74:14:06:1c:9f:80:38:14:f5:53:5b:4c:d6:c6:88:
    43:0c:0c:0f:8b:fd:e9:a2:03:fe:e0:b3:e0:1f:af:
    d9:8b:b6:11:7f:32:93:4d:a3:9e:25:20:ce:7b:7b:
    c1
```

modulus n:
```
modulus:
    00:cc:99:ce:da:af:20:d7:e2:db:8f:8b:06:34:59:
    f8:6e:2f:82:05:cd:b4:1e:9c:93:a1:56:74:3e:68:
    34:d4:21:15:6c:cc:3b:da:13:30:3c:9f:9b:66:33:
    56:bc:8f:5e:23:e8:ce:5a:f5:47:08:f6:38:d8:73:
    1e:91:52:73:75:81:c7:c1:8b:b2:24:8c:0f:3b:9b:
    a2:34:ca:94:90:d8:bf:74:40:d4:45:58:7b:26:a0:
    3b:d5:d2:a7:ea:77:a5:23:66:98:e6:8f:89:30:c7:
    ec:4c:f1:f2:0e:e6:f2:36:6b:32:3a:9b:94:fd:d4:
    c3:43:ca:cb:8b:18:55:8c:bc:15:48:7c:59:c1:d7:
    6b:df:8b:cf:a8:2c:13:b4:57:4e:b3:40:43:cd:75:
    5d:84:85:8a:fb:bc:bc:59:e0:92:18:00:ce:20:d3:
    07:fb:a7:4c:36:40:73:f6:e4:06:a1:d3:6c:73:a0:
    0e:92:de:8c:cf:5d:a6:d0:6a:9b:a5:51:25:15:43:
    52:f3:bc:ce:92:a9:74:ac:d4:cd:bb:59:1a:33:3e:
    1c:5d:7c:eb:76:fc:a3:e3:1e:66:b8:55:45:e3:9a:
    6e:f8:e8:d4:a5:89:c8:8c:06:6b:68:5f:5b:3a:1f:
    b8:5c:dc:ca:56:33:89:f2:cf:5d:d0:42:c0:1a:68:
    d9:b3
```

two secret number p and q:
```
prime1:
    00:fa:f7:1b:3a:15:0c:1d:4e:6a:d5:61:57:c2:1a:
    b5:34:6e:77:be:ab:a7:ae:70:b6:4b:58:e5:57:41:
    a9:72:0d:a8:9c:fb:7a:10:01:66:9e:23:4b:c6:3e:
    f4:3c:34:93:01:13:5e:35:df:b2:b0:1a:c0:0a:b8:
    23:28:ec:46:bc:43:db:af:76:40:e5:a9:ab:54:a5:
    f7:73:01:52:53:53:41:99:bc:d6:5a:1c:84:61:d2:
    6f:b0:7c:e4:0d:4e:05:0a:6e:d4:fa:f6:b2:10:61:
    9f:fe:41:e3:c4:72:13:8b:78:cc:ff:c7:39:e9:ec:
    c5:f9:74:69:f4:df:bf:00:fb
prime2:
    00:d0:b4:95:ef:3a:cd:06:27:de:0e:f3:7d:db:ee:
    dc:07:b8:3e:65:e1:4e:fe:07:db:b7:f1:3f:e1:f4:
    c7:a0:a0:f6:98:29:42:58:b2:0d:87:27:33:03:df:
    c8:b1:4a:bf:fd:d8:f0:02:aa:41:64:72:1b:4c:78:
    0e:cd:66:e6:ff:8e:12:84:b6:34:12:d7:d9:38:45:
    3f:8b:0c:66:1d:03:44:66:ad:e3:aa:d9:d5:df:c6:
    9c:50:02:b3:da:7f:6d:f7:2b:c3:8e:59:0c:8b:5c:
    5e:88:be:1b:ee:aa:68:ae:c0:e7:45:ae:55:48:54:
    5f:2a:7b:ca:ca:17:35:5c:a9
```

### Task 2
In this task, first of all we copy default openssl config file to our reporistory
```
cp "/usr/lib/ssl/openssl.cnf" "/home/seed/Lab/task_01/"
```
We have written a bash script to generate a Certificate Signing Request (CSR) with the server name: **www.nguyen2022.com**
```
openssl req -newkey rsa:2048 -sha256  \
	-keyout server.key   -out server.csr  \
	-subj "/CN=www.nguyen2022.com/O=Bank32 Inc./C=US" \
	-passout pass:123456
```
The result with the pair of public and private key is stored in the files server.csr and server.key respectively. Finally, we run the script to achieve decoded content of the CSR and private key files and get the output.yaml file
```
openssl req  -in server.csr -text -noout
openssl rsa  -in server.key -text -noout
```
