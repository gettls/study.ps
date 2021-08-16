N = int(input())
lst = list(map(int, input().split()))

dp = [[0] * 21 for _ in range(N)]

# 최초 인덱스의 숫자의 메모리에 경우의 수 + 1
dp[0][lst[0]] += 1

# i 는 리스트 index, j 는 현재 숫자
for i in range(1, N):
    for j in range(21):
        if dp[i - 1][j] != 0:
            # 현재의 값과 인덱스의 값
            if j + lst[i] <= 20:
                # i - 1 인덱스의 값이 정해지기 까지의 경우의 수를 i 인덱스의 더해진 값 까지의 경우의 수에 더해준다
                dp[i][j + lst[i]] += dp[i - 1][j]
            if j - lst[i] >= 0:
                dp[i][j - lst[i]] += dp[i - 1][j]

print(dp[N - 2][lst[N-1]])
