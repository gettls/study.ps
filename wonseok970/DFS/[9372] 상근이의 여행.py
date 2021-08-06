T = int(input())


def dfs(v):
    visited[v] = 1

    for i in graph[v]:
        if not visited[i]:
            dfs(i)


for _ in range(T):
    N, M = map(int, input().split())

    graph = [[] for _ in range(N + 1)]
    visited = [0] * (N + 1)
    cnt = 0

    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    dfs(1)

    print(sum(visited) - 1)

# 2

# 3 3

# 1 2
# 2 3
# 1 3

# 5 4

# 2 1
# 2 3
# 4 3
# 4 5
