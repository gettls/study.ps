from collections import deque

dx = [-1, 1]
dy = [-1, 1]

N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(M)]


def tet1(i, j):
    visited = [[0] * N for _ in range(M)]
    cnt = 0
    result = 0
    q = deque([])
    q.append([i, j])
    result += arr[i][j]

    while q:
        print(q)
        x, y = q.popleft()
        cnt += 1

        if cnt >= 4:
            print('break')
            break
        print('cnt', cnt)
        # 상, 하

        nx = x + 1
        print(nx)

        if 0 <= nx <= N:
            if not visited[nx][y]:
                result += arr[nx][y]
                print(nx, y)
                q.append([nx, y])

    return result


print(tet1(0, 0))

# def tet2():
# def tet3():
# def tet4():
# def tet5():
