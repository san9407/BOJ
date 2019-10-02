s=input()
N = len(s)
for i in range(N):
    if('A'<=s[i]<='Z'):
        print(chr(ord(s[i])+32),end="")
    else:
        print(chr(ord(s[i])-32),end="")
