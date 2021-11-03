import heapq

n, m, r = map(int, input().split())

items = []
item = list(map(int, input().split()))
graph = [[] for _ in range(n + 1)]
INF = int(1e9)

for _ in range(r):
    a, b, l = map(int, input().split())

    graph[a].append([b, l])
    graph[b].append([a, l])


def dijikstra(i):
    q = []
    result = 0
    distance = [INF] * (n + 1)
    heapq.heappush(q, [0, i])
    distance[i] = 0

    while q:
        dist, node = q.pop()

        for j in graph[node]:
            next_node, next_dist = j[0], j[1]

            cost = next_dist + dist
            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(q, [cost, next_node])

    for i in range(1, len(distance)):
        if distance[i] <= m:
            result += item[i - 1]

    return result


for i in range(1, n + 1):
    items.append(dijikstra(i))

print(max(items))

# []
# [[4, 5], [2, 3]]
# [[5, 4], [3, 3], [1, 3]]
# [[2, 3]]
# [[1, 5]]
# [[2, 4]]

# 5 4 4
# 5 7 8 2 3
# 1 4 5
# 5 2 4
# 3 2 3
# 1 2 3
