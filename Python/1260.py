import sys
N,M,K=map(int,sys.stdin.readline().split())
K-=1
adj = [[] for i in range(N)]
visit=[False]*N

for i in range(M):
    u,v=map(int,sys.stdin.readline().split())
    u-=1
    v-=1
    adj[u].append(v)
    adj[v].append(u)
for i in range(N):
    adj[i].sort()

def dfs(x):
    visit[x]=True
    print(x+1,end=" ")
    for next in adj[x]:
        if(visit[next]==False):
            dfs(next)

def bfs(x):
    q=[]
    q.append(x)
    visit[x]=True
    while(q!=[]):
        curr=q.pop(0)
        print(curr+1,end=" ")
        for next in adj[curr]:
            if(visit[next]==False):
                visit[next]=True
                q.append(next)
dfs(K)
print()
visit=[False]*N
bfs(K)
print()

