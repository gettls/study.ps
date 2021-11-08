from collections import deque


def solution(n, edge):
    answer = 0
    distance = [0] * (n + 1)
    graph = [[] for _ in range(n + 1)]

    for v in edge:
        a, b = v
        graph[a].append(b)
        graph[b].append(a)

    q = deque([1])
    distance[1] = 1

    while q:
        now_node = q.popleft()
        for g in graph[now_node]:
            next_node = g
            if distance[next_node] == 0:
                distance[next_node] = distance[now_node] + 1
                q.append(g)

    for d in distance:
        if d == max(distance):
            answer += 1
    return answer


print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))
