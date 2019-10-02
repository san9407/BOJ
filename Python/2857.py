arr=[]
for i in range(5):
      s=input()
      if "FBI" in s:
            arr.append(i+1)
N = len(arr)
if(N==0):
      print("HE GOT AWAY!")
else:
      for i in range(N):
            print(arr[i],end=" ")
