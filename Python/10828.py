import sys
T = int(input())
st=[]
for i in range(T):
    arr=sys.stdin.readline().split()
    if(arr[0]=="push"):
        st.append(int(arr[1]))
    elif(arr[0]=="pop"):
        sz=len(st)
        if(sz==0):
            print(-1)
        else:
            print(st[sz-1])
            st.pop()
    elif(arr[0]=="size"):
        print(len(st))
    elif(arr[0]=="empty"):
        if(st==[]):
            print(1)
        else:
            print(0)
    elif(arr[0]=="top"):
        sz=len(st)
        if(sz==0):
            print(-1)
        else:
            print(st[sz-1])
