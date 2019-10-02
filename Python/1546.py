N = int(input())
arr = list(map(int,input().split()))
maxx = 0

for i in range(0,N):
     maxx=max(maxx,arr[i])
for i in range(0,N):
      arr[i]=(arr[i]/maxx)*100
sum = 0
for i in range(0,N):
      sum+=arr[i]
print(sum/N)
