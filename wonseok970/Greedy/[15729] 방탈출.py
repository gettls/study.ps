N = int(input())
lst = list(map(int, input().split()))
start = [0] * (N + 2)
count = 0

for i in range(N):
    if lst[i] != start[i]:
        count += 1
        start[i] = int(not start[i])
        start[i+1] = int(not start[i+1])
        start[i+2] = int(not start[i+2])


print(count)
# refactor