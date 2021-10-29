N, M, H = map(int, input().split())

ladder = [[0] * N for _ in range(H)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def move():
    for i in range(N):
        s = i
        for j in range(H):
            # 가로선이 존재할 때, -->
            if ladder[j][s] == 1:
                s += 1
            # 가로선이 좌측에 존재할 때, <--
            elif ladder[j][s - 1] == 1:
                s -= 1
        # 출발점과 도착지점이 다를 때,
        if i != s:
            return False
    return True


def dfs(start, cnt):
    global result
    # 최초 사다리 시작
    if cnt == real_cnt:
        if move():
            result = cnt
        return
    for i in range(start, H):
        for j in range(N - 1):
            if ladder[i][j] != 1 and ladder[i][j - 1] != 1 and ladder[i][j + 1] != 1:
                ladder[i][j] = 1
                dfs(i, cnt + 1)
                ladder[i][j] = 0


result = 0
visited = [[0] * N for _ in range(H)]
for _ in range(M):
    x, y = map(int, input().split())
    ladder[x - 1][y - 1] = 1


# 추가 사다리 0 ~ 3개까지
for real_cnt in range(4):
    dfs(0, 0)

    # 0 ~ 3 개의 사다리 설치중 조작이 성공했을 때,
    if result != 0:
        print(result)
        break

# 사다리가 3개 이상 설치되거나, 조작 불가능할 경우
else:
    print(-1)
