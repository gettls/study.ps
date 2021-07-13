import heapq
import sys

input = sys.stdin.readline

V, E = map(int, input().split())
K = int(input())
graph = [[] for i in range(V + 1)]

INF = 1e9
distance = [INF] * (V + 1)

for i in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))


def dijikstra(start_node):
    q = []
    heapq.heappush(q, (0, start_node))  # 출발점으로의 거리는 항상 0이다.
    distance[start_node] = 0

    while q:
        dist, now_node = heapq.heappop(q)

        for i in graph[now_node]:
            cost = dist + i[1]  # i[1] 는 거리

            if cost < distance[i[0]]:  # i[0] 는 노드
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


dijikstra(K)

for i in range(1, V+1):
    if distance[i] >= 1e9:
        print('INF')
    else:
        print(distance[i])
