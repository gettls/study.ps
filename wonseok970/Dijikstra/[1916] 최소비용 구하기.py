import heapq
import sys

input = sys.stdin.readline

# 도시의 개수, 버스의 개수
n = int(input())
m = int(input())

INF = int(1e9)
graph = [[] for _ in range(n + 1)]
distance = [INF] * (n + 1)

for _ in range(m):
    # 출발 도시의 번호, 도착 도시의 번호, 버스 비용
    x, y, z = map(int, input().split())

    graph[x].append((y, z))

start, arrival_city = map(int, input().split())


def dijikstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now_node = heapq.heappop(q)

        for i in graph[now_node]:
            # 특정 노드까지의 거리
            cost = dist + i[1]

            # 초기화 된 dist가 기존의 거리값 보다 작을 때,
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


dijikstra(start)

print(distance[arrival_city])

# refactor