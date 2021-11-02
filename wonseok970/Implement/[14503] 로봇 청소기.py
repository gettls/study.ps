from collections import deque

N, M = map(int, input().split())
r, c, w = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
cnt = 0

#      0, 1, 2, 3
#     북, 동, 남, 서
dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

dw = [3, 0, 1, 2]

bw_x = [1, 0, -1, 0]
bw_y = [0, -1, 0, 1]


# 1 1 0
def bfs(r_, c_, w_):
    global cnt
    q = deque()
    cnt += 1
    arr[r_][c_] = -1
    q.append([r_, c_, w_])

    while q:
        x, y, z = q.popleft()

        # for a in arr:
        #     print(a)

        # 왼쪽 방향 탐색
        nx = x + dx[z]
        ny = y + dy[z]
        # print(nx, ny)
        if 0 <= nx <= N and 0 <= ny <= M:
            # 왼쪽 방향에 아직 청소하지 않은 공간이 존재할 때,
            if arr[nx][ny] == 0:
                nz = dw[z]  # 회전
                arr[nx][ny] = -1  # 현재위치 청소
                cnt += 1
                q.append([nx, ny, nz])  # 2번
                # print("case1 : ", q)

            # 네 방향 모두 청소가 이미 되어있거나 벽인 경우
            elif arr[x + 1][y] != 0 and arr[x - 1][y] != 0 and arr[x][y + 1] != 0 and arr[x][y - 1] != 0:
                # 후진
                bx = x + bw_x[z]
                by = y + bw_y[z]

                if arr[bx][by] == 1:
                    break
                else:
                    q.append([bx, by, z])
                    # print("case3 : ", q)

            # 왼쪽 방향에 청소할 공간이 없을 때,
            elif arr[nx][ny] != 0:
                nz = dw[z]
                q.append([x, y, nz])
                # print("case2 : ", q)

    return cnt


print(bfs(r, c, w))
