from collections import deque

op = ["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]


def solution(operations):
    q = deque([])

    for o in operations:
        alpha, num = o.split(" ")
        num = int(num)

        if alpha == "I":
            q.append(num)

        elif alpha == "D" and len(q) >= 1:
            q = deque(sorted(q))
            # 최대값 pop
            if num == 1:
                q.pop()

            # 최소값 pop
            elif num == -1:
                q.popleft()

    if len(q) == 0:
        return [0, 0]
    else:
        return [max(q), min(q)]


print(solution(op))

-45, 45, 333
