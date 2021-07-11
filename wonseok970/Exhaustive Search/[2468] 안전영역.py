import sys
sys.setrecursionlimit(10000)

# 상, 하, 우, 좌
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(x, y, h):
    for i in range(4):  # 상하좌우 탐색
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < N:  # 좌표를 벗어나지 않으면
            if area[nx][ny] > h and visit[nx][ny] == 0:  # 움직인 좌표가 방문하지 않고, 지정된 높이가 h 보다 구역의 높이가 높으면
                visit[nx][ny] = 1
                dfs(nx, ny, h)  # 조건에 부합한 영역이 나올때 까지 recursion 하며 visit 되는 영역을 탐색


N = int(input())

area = [list(map(int, input().split())) for x in range(N)]
result = 0

for h in range(max(map(max, area))):  # 높이는 0부터 가장 높은 영역까지
    cnt = 0
    visit = [[0] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):  # 모든 배열중,
            if area[i][j] > h and visit[i][j] == 0:  # i, j 영역이 h보다 높고, 방문한 적이 없다면
                visit[i][j] = 1
                cnt += 1
                dfs(i, j, h)  # dfs 탐색

    result = max(result, cnt) # max 영역까지의 탐색 중, 가장 많은 영역이 확보되는 개수

print(result)
