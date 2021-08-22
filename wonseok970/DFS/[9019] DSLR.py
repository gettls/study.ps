from collections import deque


# n = 1234
# d1 = 1, d2 = 2, d3= 3, d4 = 4
# d1 = 2, d2 = 3, d3 =4, d4 = 1
# d1 = n // 1000, d2 = (n-1000)/100, d3 =
# n = ((d1 * 10 + d2) * 10 + d3) * 10 + d4
# n = ((d2 * 10 + d3) * 10 + d4) * 10 + d1
# n = 2341

#

def bfs(A):
    q = deque()
    q.append([A, ''])
    check[A] = 1
    while q:
        # n == A
        n, res = q.popleft()
        if n == B:
            return res
        # D
        if n * 2 <= 9999 and check[n * 2] == 0:
            check[n * 2] = 1
            q.append([n * 2, res + 'D'])

        elif n * 2 > 9999 and check[(n * 2) % 10000] == 0:
            check[(n * 2) % 10000] = 1
            q.append([(n * 2) % 10000, res + 'D'])

        # S
        if n == 0 and check[9999] == 0:
            check[9999] = 1
            q.append([9999, res + 'S'])

        elif n != 0 and check[n - 1] == 0:
            check[n - 1] = 1
            q.append([n - 1, res + 'S'])

        # L
        move_L = (n % 1000) * 10 + n // 1000
        if check[move_L] == 0:
            check[move_L] = 1
            q.append([move_L, res + 'L'])

        # R
        move_R = (n % 10) * 1000 + n // 10
        if check[move_R] == 0:
            check[move_R] = 1
            q.append([move_R, res + 'R'])

    return res


T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    check = [0 for _ in range(10000)]

    ans = bfs(A)
    print(ans)
