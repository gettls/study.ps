from collections import deque


def solution(progresses, speeds):
    progresses = deque(progresses)
    speeds = deque(speeds)
    result = []
    answer = []

    for _ in range(len(progresses)):
        left = 100 - progresses.popleft()
        speed = speeds.popleft()

        for i in range(100):
            w = i * speed
            if w >= left:
                result.append(i)
                break

    for i in range(len(result) - 1):
        if result[i] > result[i + 1]:
            result[i + 1] = result[i]

    for i in sorted(set(result)):
        answer.append(result.count(i))

    return answer


print(solution([93, 30, 55], [1, 30, 5]))
