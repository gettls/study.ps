from collections import deque


def bfs():
    # 상, 하, 좌, 우
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    q = deque()
    q.append([0, 0, 0])
    visited[0][0][0] = 1

    while q:
        x, y, z = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if way[nx][ny] == 0 and visited[nx][ny][z] == -1:
                    visited[nx][ny][z] = visited[x][y][z] + 1
                    q.append([nx, ny, z])

                elif z == 0 and way[nx][ny] == 1 and visited[nx][ny][1] == -1:  # 벽을 만난 경우
                    visited[nx][ny][1] = visited[x][y][z] + 1
                    q.append([nx, ny, 1])


N, M = map(int, input().split())

way = [list(map(int, input())) for _ in range(N)]
visited = [[[-1] * 2 for _ in range(M)] for _ in range(N)]

bfs()

way0, way1 = visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]

# 최종 목적지 까지의 거리를 출력
if way0 == -1 and way1 != -1:
    print(way1)

elif way0 != -1 and way1 == -1:
    print(way0)

else:
    print(min(way0, way1))


