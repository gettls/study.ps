def solution(n):
    answer = ''
    result = ''
    while n:
        if n % 3 == 0:
            answer += '4'
            n = n//3 - 1
        else:
            answer += str(n % 3)
            n = n//3

    for i in range(len(answer)-1, -1, -1):
        result += answer[i]

    return result

print(solution(10))