N = int(input())

s = 0
e = int((2**63)**0.5) + 1

while s <= e:
    mid = (s + e) // 2
    square = mid ** 2

    if square >= N:
        res = mid
        e = mid - 1
    else:
        s = mid + 1
print(res)

