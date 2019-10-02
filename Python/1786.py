A = input()
B = input()
N = len(A)
M=len(B)
fail = [0]*M
j=0
for i in range(1,M):
    while(j and B[i]!=B[j]):
        j=fail[j-1]
    if(B[i]==B[j]):
        j+=1
        fail[i]=j

ans = []
j=0
for i in range(N):
    while(j and A[i]!=B[j]):
        j=fail[j-1]
    if(A[i]==B[j]):
        if(j==M-1):
            ans.append(i-M+1)
            j=fail[j]
        else:
            j+=1
sz=len(ans)
print(sz)
for i in range(sz):
    print(ans[i]+1,end=" ")
print()

