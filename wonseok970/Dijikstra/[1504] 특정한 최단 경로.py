import heapq

N, E = map(int, input().split())
graph = [[] for i in range(N + 1)]
INF = int(1e9)
K = 1

for i in range(E):
    a, b, c = map(int, input().split())

    graph[a].append((b, c))
    graph[b].append((a, c))

node1, node2 = map(int, input().split())  # 2, 3 을 거쳐간다 // 1 - 2 - 3 - 4


def dijikstra(start, index):
    distance = [INF] * (N + 1)
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now_node = heapq.heappop(q)

        for i in graph[now_node]:
            next_distance = i[1]
            next_node = i[0]

            cost = dist + next_distance

            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(q, (cost, next_node))

    return distance[index]


way1 = dijikstra(K, node1) + dijikstra(node1, node2) + dijikstra(node2, N)
way2 = dijikstra(K, node2) + dijikstra(node2, node1) + dijikstra(node1, N)

if way1 >= INF and way2 >= INF:
    print(-1)
else:
    print(min(way1, way2))