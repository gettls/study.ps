from collections import deque

# height, weight, cnt
N, M, R = map(int, input().split())

x, y = 0, 0
h, w = N, M

arr = [list(map(int, input().split())) for _ in range(N)]
q = deque([])
cnt = min(h, w) // 2

while cnt >= 1:
    # 첫행첫열 to 마지막열
    for i in range(w - 1):
        q.append(arr[x][y + i])

    # 첫행마지막열 to 마지막행
    for i in range(h - 1):
        q.append(arr[y + i][x + (w - 1)])

    # 마지막행마지막열 to 첫열
    for i in range(w - 1):
        q.append(arr[y + (h - 1)][y + (w - 1) - i])

    # 마지막행첫열 to 첫행첫열
    for i in range(h - 1):
        q.append(arr[x + (h - 1) - i][y])

    q.rotate(-R)

    # 첫행첫열 to 마지막열
    for i in range(w - 1):
        arr[x][y + i] = q.popleft()

    # 첫행마지막열 to 마지막행
    for i in range(h - 1):
        arr[y + i][x + (w - 1)] = q.popleft()

    # 마지막행마지막열 to 첫열
    for i in range(w - 1):
        arr[y + (h - 1)][y + (w - 1) - i] = q.popleft()

    # 마지막행첫열 to 첫행첫열
    for i in range(h - 1):
        arr[x + (h - 1) - i][y] = q.popleft()

    x += 1
    y += 1
    h -= 2
    w -= 2
    # 높이나 넓이 중, 길이가 2 이하가 되면
    cnt = min(h, w) // 2

for a in arr:
    for q in a:
        print(q, end=' ')
    print()

