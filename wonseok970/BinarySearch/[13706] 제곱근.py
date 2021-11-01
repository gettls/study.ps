N = int(input())

s = 1
e = N

while s <= e:
    mid = (s+e) // 2
    square = mid**2

    if square >= N: # target
        res = mid
        e = mid - 1
    else:
        s = mid + 1
print(res)

# refactor