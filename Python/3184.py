import queue
R,C=map(int,input().split())
board = []
for i in range(R):
    s=input()
    board.append(s)

dx=[-1,0,0,1]
dy=[0,-1,1,0]
visit = [[0]*C for i in range(R)]
o=0
v=0
def bfs(x,y):
    global o,v
    q=queue.Queue()
    visit[x][y]=1
    q.put((x,y))
    a=0
    b=0
    while(not q.empty()):
        cx,cy=q.get()
        if(board[cx][cy]=='o'):
            a+=1
        elif(board[cx][cy]=='v'):
            b+=1
        for i in range(4):
            nx=cx+dx[i]
            ny=cy+dy[i]
            if(nx<0 or ny<0 or nx>=R or ny>=C or board[nx][ny]=='#' or visit[nx][ny]==1):
                continue
            else:
                visit[nx][ny]=1
                q.put((nx,ny))
    if(b>=a):
        v+=b
    else:
        o+=a

for i in range(R):
    for j in range(C):
        if(board[i][j]!='#' and visit[i][j]==0):
            bfs(i,j)

print(o,v)
