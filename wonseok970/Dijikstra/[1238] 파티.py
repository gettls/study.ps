import sys
from heapq import heappop, heappush

get = sys.stdin.readline


def dijkstra(start, target):
    q = []
    distance = [INF] * (n + 1)
    distance[start] = 0
    heappush(q, (0, start))

    while q:
        dist, now_node = heappop(q)

        for node, cs in graph[now_node]:
            cost = dist + cs

            if cost < distance[node]:
                distance[node] = cost
                heappush(q, (cost, node))

    return distance[target]


# 학생 수, 간선의 개수, 목적지 노드
n, m, x = map(int, get().split())
INF = int(1e9)

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, get().split())
    graph[a].append((b, c))

max_distance = 0

for i in range(1, n + 1):
    round_trip = dijkstra(i, x) + dijkstra(x, i)
    if max_distance < round_trip:
        max_distance = round_trip

print(max_distance)

# [[1000000000, 1000000000, 1000000000, 1000000000, 1000000000],
#  [1000000000, 0, 4, 2, 6],
#  [1000000000, 1, 0, 3, 7],
#  [1000000000, 2, 6, 0, 4],
#  [1000000000, 4, 3, 6, 0]]

# [[1000000000, 1000000000, 1000000000, 1000000000, 1000000000],
#  [1000000000, 0, 4, 2, 7],
#  [1000000000, 1, 0, 5, 1000000000],
#  [1000000000, 2, 1000000000, 0, 4],
#  [1000000000, 1000000000, 3, 1000000000, 0]]

# refactor