maxx =0
curr=0
for i in range(4):
    a,b=map(int,input().split())
    curr-=a
    curr+=b
    maxx=max(maxx,curr)
print(maxx)
