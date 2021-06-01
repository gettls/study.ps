n = int(input())
budget = list(map(int, input().split()))
req = int(input())
budget.sort()

s = 1
e = max(budget)

while s <= e:
    total = 0
    mid = (s + e) // 2
    # print('s, e, mid :', s, e, mid)
    for i in range(n):
        if budget[i] < mid:
            total += budget[i]
        else:
            total += mid
    # print('total, req :', total, req)
    if total > req:
        e = mid - 1
    else:
        s = mid + 1

print(e)

