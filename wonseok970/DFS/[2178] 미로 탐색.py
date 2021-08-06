from collections import deque

N, M = map(int, input().split())

way = [list(map(int, input())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
q = deque()


def bfs():
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    q.append([0, 0])
    visited[0][0] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if way[nx][ny] == 1 and not visited[nx][ny]:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append([nx, ny])


bfs()

print(visited[N - 1][M - 1])
