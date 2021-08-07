from collections import deque

# 상, 하, 좌, 우, up, down
dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]


def bfs(x, y, z):
    q = deque()
    q.append([x, y, z])

    visited[x][y][z] = 1
    while q:
        x, y, z = q.popleft()

        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            # 행,열,높이 범위내에 포함이 되면,
            if 0 <= nx < L and 0 <= ny < R and 0 <= nz < C:
                if building[nx][ny][nz] == '.' and visited[nx][ny][nz] == 0:
                    visited[nx][ny][nz] = visited[x][y][z] + 1
                    q.append([nx, ny, nz])

                if building[nx][ny][nz] == 'E':
                    visited[nx][ny][nz] = visited[x][y][z]
                    print('Escaped in', visited[nx][ny][nz], 'minute(s).')
                    return
    print("Trapped!")


while 1:
    # 층수 L, 행 R, 열 C
    L, R, C = map(int, input().split())
    if L == 0 and R == 0 and C == 0:
        break

    building = []
    visited = [[[0] * C for _ in range(R)] for _ in range(L)]

    for i in range(L):
        building.append([list(map(str, input())) for _ in range(R)])
        input()

    # 리스트를 탐색하여 시작 지점을 발견하면 너비우선탐색을 시작한다.
    for i in range(L):
        for j in range(R):
            for k in range(C):
                if building[i][j][k] == 'S':
                    bfs(i, j, k)
