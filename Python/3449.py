T = int(input())
tc=0
while(tc<T):
    A=input()
    B=input()
    N = len(A)
    ans =0
    for i in range(N):
        if(A[i]!=B[i]):
            ans+=1
    print("Hamming distance is {}.".format(ans))
    tc+=1
