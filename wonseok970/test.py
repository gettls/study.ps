import math

n = int(input())
i = []

for _ in range(n):
    i.append(list(map(int, input().split())))

for loc in i:
    x1, y1, r1, x2, y2, r2 = loc

    dis = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

    if dis == 0 and (r1 - r2) == 0:
        result = -1

    elif dis > (r1 + r2) or max(r1, r2) - min(r1, r2) > dis:
        result = 0

    elif dis == (r1 + r2) or max(r1, r2) - min(r1, r2) == dis:
        result = 1

    elif dis < (r1 + r2) or max(r1, r2) - min(r1, r2) < dis:
        result = 2

    print(result)
