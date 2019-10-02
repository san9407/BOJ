T = int(input())
tc=0
while(tc<T):
    arr = list(map(int,input().split()))
    sum=0
    minn=1000000000
    for i in arr:
        if(i%2==0):
            sum+=i
            minn=min(minn,i)
    print(sum,minn)
    tc+=1
