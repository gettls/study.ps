from itertools import combinations

N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
chicken = []
house = []
cnt = 0

for i in range(N):
    for j in range(N):
        if arr[i][j] == 2:
            chicken.append([i + 1, j + 1])
        elif arr[i][j] == 1:
            house.append([i + 1, j + 1])

result = [0] * len(list(combinations(chicken, M)))

for comb_c in combinations(chicken, M):
    for h in house:
        min_val = 2e10
        for c in comb_c:
            min_val = min(min_val, abs(h[0] - c[0]) + abs(h[1] - c[1]))
        result[cnt] += min_val
    cnt += 1

print(min(result))
