import sys

sys.setrecursionlimit(10000)

N = int(input())

pic = [list(input()) for _ in range(N)]
visited = [[0] * N for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

RGB_cnt = 0
RB_cnt = 0


def dfs(x, y):
    visited[x][y] = 1
    color = pic[x][y]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < N:
            if not visited[nx][ny] and pic[nx][ny] == color:
                dfs(nx, ny)


for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            dfs(i, j)
            RGB_cnt += 1

# G -> R
for i in range(N):
    for j in range(N):
        if pic[i][j] == 'G':
            pic[i][j] = 'R'

# 방문 초기화
visited = [[0] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            dfs(i, j)
            RB_cnt += 1

print(RGB_cnt, RB_cnt)

