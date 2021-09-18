from collections import deque

# 세로, 가로
a, b = map(int, input().split())

time = 1
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
cz_list = [0]
arr = [list(map(int, input().split())) for _ in range(a)]


def bfs(i, j, c):
    visited = [[0] * b for _ in range(a)]
    q = deque()
    visited[i][j] = 1
    arr[i][j] = c
    q.append([i, j])

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < a and 0 <= ny < b:
                if not visited[nx][ny] and arr[nx][ny] == 0:
                    arr[nx][ny] = c
                    visited[nx][ny] = 1
                    q.append([nx, ny])


def bfs_2(i, j, n_arr):
    visited = [[0] * b for _ in range(a)]
    q = deque()
    visited[i][j] = 1
    q.append([i, j])

    if n_arr[i][j] == 0:
        return False

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < a and 0 <= ny < b:
                if not visited[nx][ny] and n_arr[nx][ny] == 1:
                    visited[nx][ny] = 1
                    q.append([nx, ny])

    return True


def div_arr(arr):
    global cnt
    for i in range(a):
        for j in range(b):
            if arr[i][j] == 0:
                cnt += 1
                bfs(i, j, cnt)


while 1:
    cnt, result = 1, 0
    cz = 0
    n_arr = [[0] * b for _ in range(a)]

    # 치즈의 개수 구하기
    for i in range(a):
        for j in range(b):
            if bfs_2(i, j, arr):
                cz += 1
    cz_list.append(cz)

    div_arr(arr)

    # 공기와 접촉한 치즈 녹이기
    for i in range(1, a):
        for j in range(1, b):
            if arr[i][j] == 1:
                if arr[i][j + 1] != 2 and arr[i - 1][j] != 2 and arr[i][j - 1] != 2 and arr[i + 1][j] != 2:
                    n_arr[i][j] = 1

    # 검증
    for i in range(a):
        for j in range(b):
            result += n_arr[i][j]
    if result == 0:
        break

    arr = n_arr
    time += 1

print(time)
print(cz_list[-1])

# 5 5
# 0 0 0 0 0
# 0 1 1 0 0
# 0 1 0 1 0
# 0 1 1 1 0
# 0 0 0 0 0