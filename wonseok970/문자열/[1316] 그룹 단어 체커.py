from collections import deque

n = int(input())


a = deque(deque(input()) for i in range(n))
b = deque([])
c = deque([])


for i in range(len(a[0])):
    get = a[0].popleft()
    if get == b[i-1]:
        continue
    else:
        b.append(get)
print(b)

for i in range(len(b)):
    get = b.popleft()
    print(get, c)
    if get in c:
        print(get, c)
        n -= 1
    else:
        c.append(get)

