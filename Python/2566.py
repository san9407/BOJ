board = []
maxx=0
ans=(0,0)
for i in range(9):
    board.append(list(map(int,input().split())))
    for j in range(9):
        if(maxx<board[i][j]):
            maxx=board[i][j]
            ans=(i,j)
print(maxx)
print(ans[0]+1,ans[1]+1)
