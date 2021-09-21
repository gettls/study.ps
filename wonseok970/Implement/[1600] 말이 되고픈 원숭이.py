from collections import deque

# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

hx = [-2, -1, 1, 2, 2, 1, -1, -2]
hy = [1, 2, 2, 1, -1, -2, -2, -1]


def bfs(i, j, k):
    visited[i][j][k] = 1
    q.append([i, j, k])

    while q:
        x, y, k = q.popleft()

        if x == H - 1 and y == W - 1:
            # print(x, y, k)
            return visited[x][y][k] - 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < H and 0 <= ny < W:
                if not visited[nx][ny][k] and arr[nx][ny] != 1:
                    visited[nx][ny][k] = visited[x][y][k] + 1
                    q.append([nx, ny, k])

        if k < K:
            for i in range(8):
                nx = x + hx[i]
                ny = y + hy[i]

                if 0 <= nx < H and 0 <= ny < W:
                    # k + 1
                    if not visited[nx][ny][k + 1] and arr[nx][ny] != 1:
                        visited[nx][ny][k + 1] = visited[x][y][k] + 1
                        q.append([nx, ny, k + 1])

    return -1


K = int(input())
W, H = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(H)]

# 말의 능력으로 k번 이동한 경우를 구분하기 위해서 3차원 배열로 선언한다.
# k = 2 일 경우 k = 1 즉 능력을 한번 사용할때 [x][y][1] 을 사용하고
# k = 2 즉 능력을 두 번 사용하게 되면 [x][y][2] 에 기록한다.
visited = [[[0] * (K + 1) for _ in range(W)] for _ in range(H)]
q = deque()

# [[0, 0], [0, 0], [0, 0], [0, 0]]
# [[0, 0], [0, 0], [0, 0], [0, 0]]
# [[0, 0], [0, 0], [0, 0], [0, 0]]
# [[0, 0], [0, 0], [0, 0], [0, 0]]

print(bfs(0, 0, 0))
