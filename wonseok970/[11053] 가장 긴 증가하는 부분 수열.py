import sys

N = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
#    [10, 20, 10, 30, 20, 50]
# DP [ 1,  1,  1,  1,  1,  1]
dp = [1] * (N+1)

for i in range(1, N):
    start = 0
    for j in range(i):
        if lst[i] > lst[j]:
            start = max(start, dp[j])
    dp[i] += start
    print(dp)

print(max(dp))


    # [1, 1, 1, 1, 1, 1]
    # [1, 2, 1, 1, 1, 1]
    # [1, 2, 1, 1, 1, 1] 1 2 1 3
    # [1, 2, 1, 3, 1, 1] 1
    # [1, 2, 1, 3, 2, 1]
    # [1, 2, 1, 3, 2, 4]
    #