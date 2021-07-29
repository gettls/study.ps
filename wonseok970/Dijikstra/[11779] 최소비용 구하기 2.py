import copy
import heapq

n = int(input())
m = int(input())
INF = 1e9
graph = [[] for _ in range(n + 1)]
distance = [INF] * (n + 1)
record_way = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())

    graph[a].append((b, c))

s, e = map(int, input().split())


def dijikstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0


    while q:
        dist, now_node = heapq.heappop(q)

        if distance[now_node] < dist:
            continue

        record_way[now_node].append(now_node)

        for i in graph[now_node]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
                record_way[i[0]] = copy.deepcopy(record_way[now_node])


dijikstra(s)

print(distance[e])
print(len(record_way[e]))
print(' '.join(map(str,record_way[e])))
