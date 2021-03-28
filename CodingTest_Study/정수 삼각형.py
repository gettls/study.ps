n = int(input())
dp = []

for i in range(n):
    dp.append(list(map(int, input().split())))

# 이전 행을 더해줘야 하므로, 첫 번째 행은 제외
for i in range(1, n):
    for j in range(i + 1):
        # j가 0인경우, 왼쪽 대각선으로 내려가는 경우
        if j == 0:
            dp[i][j] += dp[i - 1][j]
        # i와 j가 같은 경우, 오른쪽 대각선으로 내려가는 경우
        elif i == j:
            dp[i][j] += dp[i - 1][j - 1]
        # 그 사이를 지나갈 경우
        else:
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j])
# leaf 노드에 모인 최댓값 들 중, 가장 큰 값을 출력
print(max(dp[n - 1]))
