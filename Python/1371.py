cnt = [0]*26

while True:
      try:
            str=input()
            for i in str:
                  if( ord('a')<=ord(i)<=ord('z')):
                        cnt[ord(i)-97]+=1
      except:
            break
maxx= 0
for i in range(26):
      maxx=max(maxx,cnt[i])
for i in range(26):
      if(maxx==cnt[i]):
            print(chr(ord('a')+i),end="")

