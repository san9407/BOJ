tc=1
while(1):
    arr = list(input().split())
    if(arr[1]=='E'):
        break
    a=int(arr[0])
    b=int(arr[2])
    if(arr[1]==">"):
        s=str(a>b)
        print("Case {}:".format(tc),s.lower())
    elif(arr[1]==">="):
        s = str(a >= b)
        print("Case {}:".format(tc), s.lower())
    elif(arr[1]=="<"):
        s = str(a < b)
        print("Case {}:".format(tc), s.lower())
    elif(arr[1]=="<="):
        s = str(a <= b)
        print("Case {}:".format(tc), s.lower())
    elif(arr[1]=="=="):
        s = str(a == b)
        print("Case {}:".format(tc), s.lower())
    elif(arr[1]=="!="):
        s=str(a!=b)
        print("Case {}:".format(tc), s.lower())
    tc+=1
