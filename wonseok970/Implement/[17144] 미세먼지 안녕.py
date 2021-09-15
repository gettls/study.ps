# 행, 열, 횟수
R, C, T = map(int, input().split())

dust = [list(map(int, input().split())) for _ in range(R)]
sum_ = 0

for i in range(R):
    for j in range(C):
        if dust[i][j] == -1:
            top = i
            bottom = i + 1

top = top - 1
bottom = bottom - 1


def diffuse(r, c):
    # 상 하 좌 우
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    # 감소된 미세먼지량
    nd = dust[r][c] // 5

    # 최초의 미세먼지량
    pd = dust[r][c]

    for i in range(4):
        nx = r + dx[i]
        ny = c + dy[i]

        # 행과 열을 벗어나지 않는다면,
        if 0 <= nx < R and 0 <= ny < C:
            # 공기 청정기와 만난다면 continue
            if dust[nx][ny] == -1:
                continue

            d_list[nx][ny] += nd

            pd -= nd
            result = pd

    d_list[r][c] += result


def cleaner_top(r):  # 2
    # 공기청정기 윗 부분

    # 남향
    # 1 -> 2, 0 -> 1
    for i in range(r, 0, -1):
        if d_list[i][0] == -1:
            d_list[i - 1][0] = 0
        else:
            d_list[i][0] = d_list[i - 1][0]

    # 서향
    # 1 -> 0, 2 -> 1 ... 7 -> 6
    for i in range(0, C - 1):
        d_list[0][i] = d_list[0][i + 1]

    # 북향
    # 1 -> 0, 2 -> 1
    for i in range(1, r + 1):
        d_list[i - 1][C - 1] = d_list[i][C - 1]

    # 동향
    # 1 -> 2, 2 -> 3, 6 -> 7
    for i in range(C - 1, 1, -1):
        d_list[r][i] = d_list[r][i - 1]

    # 청정기 바로 앞
    d_list[r][1] = 0


def cleaner_bottom(r):  # 3
    # 공기 청정기 아랫부분

    # 북향
    # 5 -> 4, 6 -> 5
    for i in range(r, R - 1):  # 3 4 5
        if d_list[i][0] == -1:
            d_list[i + 1][0] = 0
        else:
            d_list[i][0] = d_list[i+1][0]

    # 서향
    for i in range(0, C - 1):
        d_list[R - 1][i] = d_list[R - 1][i + 1]

    # 남향
    # 5 -> 6, 4 -> 5, 3 -> 4
    for i in range(R - 1, r, -1):  # 6 5 4
        d_list[i][C - 1] = d_list[i - 1][C - 1]

    # 동향
    # 7 -> 8, 6 -> 7 ... 2 -> 3
    for i in range(C - 1, 1, -1):
        d_list[r][i] = d_list[r][i - 1]

    # 청정기 바로 앞
    d_list[r][1] = 0


# 최초 1회
for _ in range(T):
    d_list = [[0] * C for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if dust[i][j] == -1:
                d_list[i][j] = -1

            elif dust[i][j] != 0:
                diffuse(i, j)

    cleaner_top(top)
    cleaner_bottom(bottom)

    dust = d_list

for i in range(R):
    for j in range(C):
        if dust[i][j] != -1:
            sum_ += dust[i][j]

print(sum_)
