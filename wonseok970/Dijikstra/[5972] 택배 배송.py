from collections import deque
import heapq

N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]
distance = [int(1e9)] * (N + 1)

for i in range(M):
    ai, bi, ci = map(int, input().split())
    graph[ai].append([bi, ci])
    graph[bi].append([ai, ci])


def dijikstra():
    q = []
    heapq.heappush(q, [0, 1])
    distance[0] = 0

    while q:
        dist, node = heapq.heappop(q)

        for i in graph[node]:
            next_distance = i[1]
            next_node = i[0]

            cost = dist + next_distance

            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(q, [cost, next_node])

    return distance[N]


print(dijikstra())
