T = int(input())
tc=0
while(tc<T):
    cnt = [0]*26
    s = input()
    for i in s:
        cnt[ord(i)-65]+=1
    sum=0
    for i in range(26):
        if(cnt[i]==0):
            sum+=65+i
    print(sum)
    tc+=1
