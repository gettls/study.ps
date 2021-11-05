from collections import deque


def solution(rows, columns, queries):
    arr = [[0] * columns for _ in range(rows)]
    cnt = 0
    answer = []
    for i in range(rows):
        for j in range(columns):
            cnt += 1
            arr[i][j] = cnt

    for qur in queries:
        q = deque([])
        x1, y1, x2, y2 = qur

        for i in range(y1 - 1, y2):
            q.append(arr[x1 - 1][i])

        for i in range(x1, x2):
            q.append(arr[i][y2 - 1])

        for i in range(y2 - 2, y1 - 2, -1):
            q.append(arr[x2 - 1][i])

        for i in range(x2 - 2, x1 - 1, -1):
            q.append(arr[i][y1 - 1])

        q.rotate(1)
        answer.append(min(q))

        for i in range(y1 - 1, y2):
            arr[x1 - 1][i] = q.popleft()

        for i in range(x1, x2):
            arr[i][y2 - 1] = q.popleft()

        for i in range(y2 - 2, y1 - 2, -1):
            arr[x2 - 1][i] = q.popleft()

        for i in range(x2 - 2, x1 - 1, -1):
            arr[i][y1 - 1] = q.popleft()

    return answer
