# 물건의 수, 최대 무게
N, K = map(int, input().split())

stuff = [[0]]

# 무게에 따른 n 까지 물건들의 가치
dp = [[0] * (K+1) for _ in range(N+1)]

for _ in range(N):
    stuff.append(list(map(int, input().split())))

for i in range(1, N + 1):
    for j in range(1, K + 1):
        w, v = stuff[i][0], stuff[i][1]

        # j[최대무게] 의 값보다 w[물건의 무게] 가 무겁다면
        if j < w:
            # 이전 값
            dp[i][j] = dp[i-1][j]

        # j[최대무게] 의 공간에 여유가 있을 때
        else:
            # 최대값(이전값의 j - 물건값 + 가치, 이전 값)
            dp[i][j] = max(dp[i-1][j-w] + v, dp[i-1][j])

print(dp[N][K])

# 6 13
# 4 8
# 3 6
# 5 12


#   0 1 2 3 4 5 6 7
# 0 0 0 0 0 0 0 0 0
# 1 0 0 0 0 0 0 13 0
# 2 0 0 0 0 0 0 0 0
# 3 0 0 0 0 0 0 0 0
# 4