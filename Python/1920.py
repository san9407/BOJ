import sys

N = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
s=set()
for i in range(N):
    s.add(arr[i])
M = int(sys.stdin.readline())
q = list(map(int,sys.stdin.readline().split()))
for i in range(M):
    if(q[i] in s):
        print(1)
    else:
        print(0)

