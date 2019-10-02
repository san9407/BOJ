import sys
V,E = map(int,sys.stdin.readline().split())
par = []
ks = []
for i in range(V):
    par.append(i)
for i in range(E):
    u,v,w=map(int,sys.stdin.readline().split())
    u-=1
    v-=1
    ks.append((w,u,v))
ks.sort()

def find(x):
    if(x==par[x]):
        return x
    else:
        par[x]=find(par[x])
        return par[x]

def merge(x,y):
    x=find(x)
    y=find(y)
    if(x==y):
        return False
    par[x]=y
    return True

ans=0
cnt=0
for i in range(E):
    if(merge(ks[i][1],ks[i][2])):
        ans+=ks[i][0]
        cnt+=1
        if(cnt==V-1):
            break
print(ans)

