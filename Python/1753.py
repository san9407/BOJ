import sys
import queue

N,M = map(int,sys.stdin.readline().split())
K = int(sys.stdin.readline())
K-=1

adj = [[] for i in range(N)]
dist = [1000000000]*N
visit = [False]*N

for i in range(M):
    u,v,w = map(int,sys.stdin.readline().split())
    u-=1
    v-=1
    adj[u].append((v,w))

def dijk(start):
    pq=queue.PriorityQueue()
    pq.put((0,start))
    dist[start]=0
    while(not pq.empty()):
        cost,curr = pq.get()
        if(visit[curr]):
            continue
        visit[curr]=True
        for next,nextCost in adj[curr]:
            if(dist[next]>dist[curr]+nextCost):
                dist[next]=dist[curr]+nextCost
                pq.put((dist[next],next))

dijk(K)
for i in range(N):
    if(dist[i]==1000000000):
        print("INF")
    else:
        print(dist[i])


