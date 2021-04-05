N = int(input())

P = list(map(int, input().split()))

dp = [0] * N
dp[0] = P[0]

for i in range(1, N):
    for j in range(0, i):
        if dp[i] < max(P[i - j - 1] + dp[j], P[i]):
            dp[i] = max(P[i - j - 1] + dp[j], P[i])

print(dp[N - 1])

# 1장의 경우 dp[0] = 1
# P[0] = 1
#
# 2장의 경우 dp[1]
# P[0] + dp[0]
# P[1]
# 2장모두 사거나 or 1장을 사고 1장을 살때의 max
#
# 3장의 경우 dp[2]
# P[2]
# p[1] + dp[1]
# p[0] + dp[2]
# 3장 모두 사거나 or 2장을 사고 1장을 살때의 max
# or 1장을 사고 2장을 살때의 max
#
# 4장의 경우 d[3]
# P[3] 4장 다삼
# P[2] + dp[0] 3장만 사고 1장 최대값
# P[1] + dp[1] 2장만 사고 2장 최대값
# P[0] + dp[2] 1장만 사고 3장 최대값
