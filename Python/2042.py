import sys
N,M,K = map(int,sys.stdin.readline().split())
M+=K
arr = []
tree = [0]*4*N
for i in range(N):
    x=int(sys.stdin.readline())
    arr.append(x)

def init(node,start,end):
    if(start==end):
        tree[node]=arr[start]
    else:
        mid=(start+end)//2
        init(node*2,start,mid)
        init(node*2+1,mid+1,end)
        tree[node]=tree[node*2]+tree[node*2+1]

def update(node,start,end,index,diff):
    if(index<start or index>end):
        return
    tree[node]+=diff
    if(start!=end):
        mid=(start+end)//2
        update(node*2,start,mid,index,diff)
        update(node*2+1,mid+1,end,index,diff)

def find(node,start,end,left,right):
    if(right<start or left>end):
        return 0
    if(left<=start and end<=right):
        return tree[node]
    mid=(start+end)//2
    return find(node*2,start,mid,left,right)+find(node*2+1,mid+1,end,left,right)

init(1,0,N-1)
for i in range(M):
    a,b,c=map(int,sys.stdin.readline().split())
    b-=1
    if(a==1):
        diff=c-arr[b]
        arr[b]=c
        update(1,0,N-1,b,diff)
    else:
        c-=1
        print(find(1,0,N-1,b,c))
