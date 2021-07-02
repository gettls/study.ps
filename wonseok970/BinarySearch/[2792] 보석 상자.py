# 아이들의 수, 색상의 수
N, M = map(int, input().split())

jwl = []

for _ in range(M):
    jwl.append(int(input()))

s = 1
e = max(jwl)

get = 1e9

while s <= e:
    mid = (s + e) // 2
    envy = 0
    for i in range(len(jwl)):
        envy += jwl[i] // mid
        if jwl[i] % mid != 0:
            envy += 1

    if N >= envy:
        e = mid - 1
        if mid < get:
            get = mid
    else:
        s = mid + 1

print(get)

# AAAAAAA BBBB

# AAA AAA A BBB B
# AA AA AA A BBBB
