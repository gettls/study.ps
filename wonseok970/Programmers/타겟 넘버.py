from collections import deque


def solution(numbers, target):
    answer = 0
    q = deque()

    # +와 -의 경우를 q에 넣는다
    q.append([numbers[0], 0])  # value, index
    q.append([-1 * numbers[0], 0])  # value, index

    while q:

        value, index = q.popleft()
        index += 1

        if index < len(numbers):
            # 기존의 값 -+ 현 인덱스 값, index
            q.append([value + numbers[index], index])
            q.append([value - numbers[index], index])

        # index 가 배열의 길이를 벗어날 때 [ 리스트의 값들을 모두 사용함 ]
        else:
            if value == target:
                answer += 1

    return answer


print(solution([1, 1, 1, 1, 1], 3))
