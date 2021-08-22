from collections import deque
import sys

sys.setrecursionlimit(100000)

N = int(input())

m = [list(map(int, input().split())) for _ in range(N)]
visited = [[0] * N for _ in range(N)]

result = 1e9
cnt = 1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(y, x):
    m[y][x] = cnt
    visited[y][x] = 1

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < N:
            if visited[ny][nx] == 0 and m[ny][nx]:
                dfs(ny, nx)


def bfs(num):
    global result
    way = [[0] * N for _ in range(N)]
    q = deque()

    for i in range(N):  # 섬들의 위치 모두 큐에 저장
        for j in range(N):
            if m[i][j] == num:
                q.append([i, j])
                way[i][j] = 1

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= nx < N and 0 <= ny < N:
                # 다른 섬에 도착한 경우
                if m[ny][nx] > 0 and m[ny][nx] != num:
                    result = min(result, way[y][x])
                    return
                # 만약 바다이고, 간척 사업도 안된 곳이라면 새로 거리를 더해준다
                if m[ny][nx] == 0 and way[ny][nx] == 0:
                    way[ny][nx] = way[y][x] + 1
                    q.append([ny, nx])


for i in range(N):
    for j in range(N):
        if visited[i][j] == 0 and m[i][j] == 1:
            dfs(i, j)
            cnt += 1

for i in range(1, cnt):
    bfs(i)

print(result-1)

# 4
# [1, 1, 1, 2, 3, 4, 5, 0, 0, 0]
# [1, 1, 1, 1, 2, 3, 4, 5, 0, 0]
# [1, 0, 1, 1, 2, 3, 4, 5, 0, 0]
# [2, 0, 1, 1, 1, 2, 3, 4, 5, 0]
# [3, 3, 2, 1, 2, 3, 4, 0, 0, 0]
# [4, 4, 3, 2, 3, 4, 5, 0, 0, 0]
# [5, 5, 4, 3, 4, 5, 0, 0, 0, 0]
# [0, 0, 5, 4, 0, 0, 0, 0, 0, 0]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
#
# 5
# [0, 0, 0, 5, 4, 3, 2, 1, 1, 1]
# [0, 0, 0, 0, 5, 4, 3, 2, 1, 1]
# [0, 0, 0, 0, 5, 4, 3, 2, 1, 1]
# [0, 0, 0, 0, 0, 5, 4, 3, 2, 1]
# [0, 0, 0, 0, 0, 0, 5, 0, 0, 1]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 2]
# [0, 0, 0, 0, 0, 0, 0, 5, 4, 3]
# [0, 0, 0, 0, 0, 0, 0, 0, 5, 4]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 5]
#
# 4
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# [0, 0, 0, 0, 4, 4, 0, 0, 0, 0]
# [0, 0, 5, 4, 3, 3, 4, 0, 0, 0]
# [0, 5, 4, 3, 2, 2, 3, 4, 0, 0]
# [0, 4, 3, 2, 1, 1, 2, 3, 4, 0]
# [0, 0, 0, 2, 1, 1, 1, 2, 3, 4]
# [0, 0, 0, 0, 0, 0, 2, 3, 4, 0]
#
# 4


# def bfs(z):
#     global result
#     way = [[-1] * N for _ in range(N)]
#     q = deque()
#
#     # 섹터별로 섬을 찾아 큐에 넣어준다
#     for i in range(N):
#         for j in range(N):
#             if m[i][j] == z:
#                 q.append([i, j])
#                 way[i][j] = 0
#
#     while q:
#         y, x = q.popleft()
#
#         for i in range(4):
#             ny = y + dy[i]
#             nx = x + dx[i]
#
#             if ny < 0 or ny >= N or nx < 0 or nx >= N:
#                 continue
#             if m[ny][nx] > 0 and m[ny][nx] != z:
#                 result = min(result, way[y][x])
#                 for k in range(N):
#                     print(way[k])
#                 print()
#                 return
#             if m[nx][ny] == 0 and way[ny][nx] == -1:
#                 way[ny][nx] = way[y][x] + 1
#                 q.append([ny, nx])
