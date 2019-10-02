import sys
T = int(input())
q=[]
for i in range(T):
    arr=sys.stdin.readline().split()
    if(arr[0]=="push"):
        q.append(int(arr[1]))
    elif(arr[0]=="pop"):
        if(q==[]):
            print(-1)
        else:
            print(q[0])
            q.pop(0)
    elif(arr[0]=="size"):
        print(len(q))
    elif(arr[0]=="empty"):
        if(q==[]):
            print(1)
        else:
            print(0)
    elif(arr[0]=="front"):
        if(q==[]):
            print(-1)
        else:
            print(q[0])
    elif(arr[0]=="back"):
        N=len(q)
        if(N==0):
            print(-1)
        else:
            print(q[N-1])
