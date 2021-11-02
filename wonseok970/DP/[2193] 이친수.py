N = int(input())

dp = [0] * 91
dp[1] = 1
dp[2] = 1
dp[3] = 2

# lst = [0] * N
# lst[0] = 1
# lst[1] = 0

for i in range(4, N + 1):
    dp[i] = dp[i - 2] + dp[i - 1]

print(dp[N])

# refactor