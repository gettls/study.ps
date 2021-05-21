import sys

get = sys.stdin.readline()

n, c = map(int, get.split())
q = []

for _ in range(n):
    q.append(int(input()))
q.sort()

start = 1
end = q[-1] - q[0]
answer = 0
# 1 2 4 8 9
while start <= end:
    mid = (start + end) // 2
    cnt = 1
    install_house = q[0]

    for i in range(1, n):
        #
        if q[i] >= install_house + mid:
            cnt += 1
            install_house = q[i]

    if cnt >= c:
        start = mid + 1
        answer = mid
    else:
        end = mid -1

print(answer)