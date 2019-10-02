N,M = map(int,input().split())
mp={}
for i in range(M):
    a,b=map(int,input().split())
    if(a>b):
        a,b=b,a
    a-=1
    b-=1
    mp[(a,b)]=1


ans=0
for i in range(0,N):
    for j in range(i+1,N):
        for k in range(j+1,N):
            if((i,j) in mp or (i,k) in mp or (j,k) in mp):
                continue
            else:
                ans+=1
print(ans)
