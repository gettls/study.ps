def solution(brown, yellow):
    divisor = []
    answer = []

    for i in range(1, yellow + 1):
        if yellow % i == 0 and i >= (yellow // i):
            divisor.append([i + 2, (yellow // i) + 2])

    while divisor:
        a, b = divisor.pop()

        if (a * b) - yellow == brown:
            answer.append([a, b])

    return answer[0]


print(solution(8, 1))
