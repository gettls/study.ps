from collections import deque


def solution(n, edge):
    answer = 0
    distance = [int(1e9)] * (n + 1)
    graph = [[] for _ in range(n + 1)]

    for v in edge:
        a, b = v
        graph[a].append((b, 1))
        graph[b].append((a, 1))
    q = deque([])
    q.append([0, 1])
    distance[1] = 0
    distance[0] = 0
    while q:
        dist, now_node = q.popleft()
        for g in graph[now_node]:
            next_dist = g[1]
            next_node = g[0]

            cost = next_dist + dist
            if distance[next_node] > cost:
                distance[next_node] = cost
                q.append([cost, next_node])

    for d in distance:
        if d == max(distance):
            answer += 1
    return answer