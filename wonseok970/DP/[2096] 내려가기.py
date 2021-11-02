import sys
input = sys.stdin.readline
N = int(input())
max_dp = [[0] * 3 for _ in range(2)]
min_dp = [[0] * 3 for _ in range(2)]

for i in range(N):
    score = list(map(int, input().split()))

    max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + score[0]
    max_dp[1][1] = max(max_dp[0][0], max_dp[0][1], max_dp[0][2]) + score[1]
    max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + score[2]

    min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + score[0]
    min_dp[1][1] = min(min_dp[0][0], min_dp[0][1], min_dp[0][2]) + score[1]
    min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + score[2]

    # 반복문을 진행할 때 마다, i번째 행의 최대경로를 다시 0행에 저장
    max_dp[0][0], max_dp[0][1], max_dp[0][2] = max_dp[1][0], max_dp[1][1], max_dp[1][2]
    # 반복문을 진행할 때 마다, i번째 행의 최소경로를 다시 0행에 저장
    min_dp[0][0], min_dp[0][1], min_dp[0][2] = min_dp[1][0], min_dp[1][1], min_dp[1][2]

print(max(max_dp[0]), min(min_dp[0]))


# -- 메모리 초과 --
# import sys
# input = sys.stdin.readline()
# N = int(input())
# score = []
# dp_min = [[0] * 3 for _ in range(N+1)]
# dp_max = [[0] * 3 for _ in range(N+1)]
# for i in range(N):
#     score.append(list(map(int, input().split())))
#
# for i in range(1, N+1):
#
#     dp_max[i][0] = max(dp_max[i - 1][0], dp_max[i - 1][1]) + score[i - 1][0]
#     dp_max[i][1] = max(dp_max[i - 1][0], dp_max[i - 1][1], dp_max[i - 1][2]) + score[i - 1][1]
#     dp_max[i][2] = max(dp_max[i - 1][1], dp_max[i - 1][2]) + score[i - 1][2]
#     max_val = max(dp_max[N])
#
#     dp_min[i][0] = min(dp_min[i - 1][0], dp_min[i - 1][1]) + score[i - 1][0]
#     dp_min[i][1] = min(dp_min[i - 1][0], dp_min[i - 1][1], dp_min[i - 1][2]) + score[i - 1][1]
#     dp_min[i][2] = min(dp_min[i - 1][1], dp_min[i - 1][2]) + score[i - 1][2]
#     min_val = min(dp_min[N])
#
#
# print(max_val, min_val)
#     0 1 2
# 0 / 1 2 3
# 1 / 4 5 6
# 2 / 4 9 0

# refactor
