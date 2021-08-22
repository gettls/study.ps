# 0 부터 20까지 정수 2개를 더해서 합이 20이 되는 경우
N, K = map(int, input().split())

# 0, 1, 2, 3, 4, ... 19, 20

dp = [[0] * (K + 1) for _ in range(N + 1)]
dp[0][0] = 1

for n in range(0, N + 1):
    for k in range(1, K + 1):
        dp[n][k] = dp[n-1][k] + dp[n][k-1]

print(dp[N][K] % 1000000000)

# dp[n][k] = dp[0][k-1] + dp[1][k-1] + ... + dp[n-1][k-1] + dp[n][k-1]
# dp[n-1][k] = dp[0][k-1] + dp[1][k-1] + ... dp[n-1][k-1]
# dp[n][k] = dp[n-1][k] + dp[n][k-1]