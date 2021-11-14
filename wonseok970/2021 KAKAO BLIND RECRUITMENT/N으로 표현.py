def solution(N, number):
    dp = [set([int(str(N) * i)]) for i in range(1, 9)]

    # 표현하려는 수와 사용하려는 수가 같으면 한번만 사용해도 된다.
    if N == number:
        return 1

    for i in range(8):
        for j in range(i):
            for case1 in dp[j]:  # 0, 1, 2
                for case2 in dp[i - j - 1]:  # 2, 1, 0
                    dp[i].add(case1 + case2)
                    dp[i].add(case1 - case2)
                    dp[i].add(case1 * case2)
                    if case2 != 0:
                        dp[i].add(case1 // case2)

        # number 가 dp[i] 안에 포함 될 경우
        if number in dp[i]:
            return i + 1
    # 아닐경우
    return -1


print(solution(5, 12))

# 1번만 사용
# [1]

# 2번만 사용
# [1] * 사칙연산

# 3번만 사용
# [1] 사칙연산 [2]
# [2] 사칙연산 [1]

# 4번만 사용
# [1] 사칙연산 [3]
# [2] 사칙연산 [2]
# [3] 사칙연산 [1]
