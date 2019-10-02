T = int(input())
tc =0
while(tc<T):
    N,s=input().split()
    n = int(N)
    m = len(s)
    for i in range(m):
        for j in range(n):
            print(s[i],end="")
    print()
    tc+=1
