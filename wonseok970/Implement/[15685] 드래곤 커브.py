N = int(input())

# 0 1 2 3
# 우 상 좌 하
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
result = 0

map_ = [[0] * 101 for _ in range(101)]
for _ in range(N):
    x, y, d, g = map(int, input().split())
    line = [d]
    map_[x][y] = 1

    for _ in range(g):
        r_line = list(reversed(line))
        for r in r_line:
            # 리버스 값이 4일경우 0
            if r + 1 == 4:
                line.append(0)
            # 아닐경우 인덱스값 + 1
            else:
                line.append(r + 1)

    # 방향에 따른 좌표 기록
    for i in line:
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx <= 100 and 0 <= ny <= 100:
            map_[nx][ny] = 1
            x, y = nx, ny

# [n, m], [n, m+1], [n+1, m], [n+1][m+1]
for i in range(101):
    for j in range(101):
        if map_[i][j] and map_[i][j+1] and map_[i+1][j] and map_[i+1][j+1]:
            result += 1


print(result)

# 방향이 0일 때,
# 0 세대 : 0
# 1 세대 : 0, 1
# 2 세대 : 0, 1, 2, 1
# 3 세대 : 0, 1, 2, 1, 2, 3, 2, 1
# 4 세대 : 3세대 + 2, 3, 0, 3, 2, 3, 2, 1

# 3 3 0 1