x = input()
y = input()

dp = [[0] * (len(x) + 1) for _ in range(len(y) + 1)]

for i in range(1, len(y) + 1):
    for j in range(1, len(x) + 1):
        if x[j - 1] == y[i - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[-1][-1])
