def solution(n, s, a, b, fares):
    answer = 0
    INF = int(1e9)

    dist = [[INF] * n for _ in range(n)]
    result = []

    for f in fares:
        x, y, z = f[0], f[1], f[2]
        dist[x - 1][y - 1] = z
        dist[y - 1][x - 1] = z

    for i in range(n):
        dist[i][i] = 0

    for k in range(n):  # 거치는 점
        for i in range(n):  # 시작점
            for j in range(n):  # 도착점
                # k 노드를 거쳐가는 경로가 기존 경로보다 짧을 때,
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    for i in range(n):
        result.append(dist[i][a - 1] + dist[i][b - 1] + dist[s - 1][i])

    answer = min(result)

    return answer


print(solution(6, 4, 5, 6, [[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]))
#         A    B
# s = 4 / 35 + 66 / 기준

# s = 1 / 25 + 63 / 10 = 98
# s = 2 / 48 + 0  / 66 = 114
# s = 3 / 26 + 22 / 51 = 99
# s = 5 / 2  + 46 / 34 = 82
# s = 6 / 0  + 48 / 35 = 83


# [0, 63, 41, 10, 24, 25]
# [63, 0, 22, 66, 46, 48]
# [41, 22, 0, 51, 24, 26]
# [10, 66, 51, 0, 34, 35]
# [24, 46, 24, 34, 0, 2]
# [25, 48, 26, 35, 2, 0]


# def floy_warshall():


# def dijikstra(start):
#     q = []
#     dist = [INF] * (n + 1)
#     heapq.heappush(q, (0, start))
#     dist[start] = 0
#
#     while q:
#         now_cost, now_node = heapq.heappop(q)
#
#         for new_node, new_cost in graph[now_node]:
#             cost = new_cost + now_cost
#             if cost < dist[new_node]:
#                 dist[new_node] = cost
#                 heapq.heappush(q, (cost, new_node))
#
#     return dist
#
#
# fares = [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]
#
# graph = [[] for _ in range(n + 1)]
#
# for f in fares:
#     x, y, z = f[0], f[1], f[2]
#     graph[x].append((y, z))
#     graph[y].append((x, z))
#
# dist_s = dijikstra(s)
# dist_A = dijikstra(a)
# dist_B = dijikstra(b)
#
# print(dist_s, dist_A, dist_B)
