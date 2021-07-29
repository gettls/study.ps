from collections import deque

K = int(input())

lst = deque(input() for i in range(K))
result = deque()

while lst:
    get = lst.popleft()
    if get != '0':
        result.append(int(get))
    elif get == '0':
        result.pop()

print(sum(result))
