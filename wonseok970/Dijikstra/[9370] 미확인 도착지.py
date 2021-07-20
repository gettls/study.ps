import heapq
import sys

input = sys.stdin.readline

T = int(input())
INF = int(1e9)


def dijikstra(start):
    q = []
    distance = [INF] * (n + 1)
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        now_dis, now_node = heapq.heappop(q)
        for new_node, new_dis in graph[now_node]:
            cost = now_dis + new_dis
            if cost < distance[new_node]:
                distance[new_node] = cost
                heapq.heappush(q, (cost, new_node))

    return distance


for _ in range(T):
    # 교차로[노드], 도로[간선], 목적지
    result = []
    n, m, t = map(int, input().split())

    # 출발지, g-h를 방문
    s, g, h = map(int, input().split())

    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d))
        graph[b].append((a, d))

    target = [int(input()) for _ in range(t)]

    way_s = dijikstra(s) # 2
    way_g = dijikstra(g) # 3
    way_h = dijikstra(h) # 1

    for t in target:
        s_g_h_t = way_s[g] + way_g[h] + way_h[t]
        s_h_g_t = way_s[h] + way_h[g] + way_g[t]
        s_t = way_s[t]

        if s_t >= min(s_g_h_t, s_h_g_t):
            result.append(t)
    result.sort()

    for r in result:
        print(r, end=' ')




    # way, end = dijikstra(s)  # 1, 3
    #
    # for t in target:
    #     g_h_cost = way + g_h(g, h) + g_h(end, t)
    #     min_cost = g_h(s, t)
    #     if g_h_cost <= min_cost:
    #         result.append(str(t))
    #
    # print(' '.join(sorted(result)))

# 6 9 2
# 2 3 1

# 1 2 1
# 1 3 3
# 2 4 4
# 2 5 5
# 3 4 3
# 3 6 2
# 4 5 4
# 4 6 3
# 5 6 7

# 5
# 6
