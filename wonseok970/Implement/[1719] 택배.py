import heapq

n, m = map(int, input().split())
INF = int(1e9)
graph = [[] for _ in range(n + 1)]
way = [[0] * n for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])


def dijikstra(start):
    q = []
    distance = [INF] * (n + 1)
    new = [INF] * (n + 1)
    heapq.heappush(q, ([0, start]))
    distance[start] = 0

    while q:
        dist, node = q.pop()

        for i in graph[node]:
            next_dist = i[1]
            next_node = i[0]
            cost = dist + next_dist
            if cost < distance[next_node]:
                distance[next_node] = cost

                if node != start:
                    new[next_node] = new[node]
                else:
                    new[next_node] = next_node
                heapq.heappush(q, ([cost, next_node]))

    for i in range(1, len(new)):
        if new[i] == INF:
            way[start - 1][i - 1] = 0
        else:
            way[start - 1][i - 1] = new[i]

    return new


for i in range(1, n + 1):
    dijikstra(i)

for i in range(n):
    for j in range(n):
        if i == j:
            way[i][j] = '-'

for w in way:
    for result in w:
        print(result, end=' ')
    print()