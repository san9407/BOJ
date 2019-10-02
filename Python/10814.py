from sys import stdin
N = int(stdin.readline())
arr = []

for i in range(N):
    arr.append(list(stdin.readline().split()))
arr.sort(key=lambda arr: int(arr[0]))

for i in arr:
    print(i[0], i[1])
