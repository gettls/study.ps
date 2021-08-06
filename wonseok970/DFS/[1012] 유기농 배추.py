import sys
sys.setrecursionlimit(10000)

T = int(input())


def dfs(a, b):
    # dx = [-1, 1, 0, 0]
    # dy = [0, 0, -1, 1]

    if 0 <= a < N and 0 <= b < M:
        if not visited[a][b] and field[a][b] == 1:
            visited[a][b] = 1
            dfs(a - 1, b)
            dfs(a + 1, b)
            dfs(a, b - 1)
            dfs(a, b + 1)
            return 1
        else:
            return 0


while T:
    cnt = 0
    M, N, K = map(int, input().split())

    visited = [[0] * M for _ in range(N)]
    field = [[0] * M for _ in range(N)]
    for _ in range(K):
        x, y = map(int, input().split())
        field[y][x] = 1

    for i in range(N):
        for j in range(M):
            if dfs(i, j) == 1:
                cnt += 1
    T -= 1
    print(cnt)



# 0 0 0 0 1
# 0 0 0 0 0
# 1 1 1 1 1