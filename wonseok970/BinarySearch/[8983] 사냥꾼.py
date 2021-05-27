import sys
input = sys.stdin.readline

# 사대의 수, 동물의 수, 사정거리
M, N, L = map(int, input().split())

sade = list(map(int, input().split()))
sade.sort()
animal = []

cnt = 0
for i in range(N):
    animal.append(tuple(map(int, input().split())))

for a, b in animal:
    start = 0
    end = len(sade) - 1

    while start < end:
        mid = (start + end) // 2

        if sade[mid] < a:
            start = mid + 1
        else:
            end = mid

    if abs(sade[end]-a)+b <= L or abs(sade[end-1]-a)+b <= L:
        cnt += 1

print(cnt)
