from collections import deque

# 정점, 간선, 탐색을 시작하는 노드번호
N, M, V = map(int, input().split())
visited_dfs = [False] * (N+1)
visited_bfs = [False] * (N+1)

graph = [[] for _ in range(N)]

# 노드간의 정보 연결
for i in range(0, M):
    a, b = list(map(int, input().split()))
    graph[a - 1].append(b)
    graph[b - 1].append(a)
    for j in range(0, N):
        graph[j].sort()


def dfs(graph, V, visited):
    visited[V] = True
    print(V, end=' ')

    for i in graph[V - 1]:
        if not visited[i]:
            dfs(graph, i, visited)


def bfs(graph, V, visited):
    # 큐 구현을 위해 deque 라이브러리 사용
    queue = deque([V])
    visited[V] = True

    while queue:
        # 큐에서 원소하나를 POP
        v = queue.popleft()
        print(v, end=' ')

        for i in graph[v - 1]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


dfs(graph, V, visited_dfs)
print()
bfs(graph, V, visited_bfs)
