with open('file.txt', 'rb') as f:
    f1 = f.read()
with open('common_decrypted_file.txt', 'rb') as f:
    f2 = f.read()
cnt = 0
for i in range(min(len(f1), len(f2))):
    if f1[i] != f2[i]:
        cnt += 1
print("differences: "+str(cnt))
