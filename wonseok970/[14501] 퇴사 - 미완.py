N = int(input())

t = [0]
p = [0]
dp = [0] * (N + 1)

for i in range(N):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)

for i in range(1, N + 1):
    if i + t[i] > N:
        continue
    else:
        dp[i] = max(dp[i + t[i]] + p[i], dp[i + 1])

print(dp[N])
