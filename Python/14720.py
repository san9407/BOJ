import sys
N = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
prev=-1
ans =0
flag= False
for i in range(N):
    if(not flag and arr[i]==0):
        flag=True
        ans+=1
        prev=0
    else:
        if(arr[i]==0 and prev==2):
            ans+=1
            prev=0
        elif(arr[i]==1 and prev==0):
            ans+=1
            prev=1
        elif(arr[i]==2 and prev==1):
            ans+=1
            prev=2
print(ans)
