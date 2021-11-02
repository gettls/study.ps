# 랜선의 개수, 필요한 랜선의 개수
k, n = map(int, input().split())
result = 0
cm = [int(input()) for i in range(k)]

start, end = 1, max(cm)

while start <= end:
    mid = (start+end) // 2
    lines = 0
    for i in cm:
        lines += i // mid

    if lines >= n:
        start = mid + 1
    else:
        end = mid - 1

print(end)

# refactor