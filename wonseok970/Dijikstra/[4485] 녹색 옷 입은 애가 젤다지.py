import heapq

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
INF = 1e9
cnt = 1


def dijikstra():
    q = []
    heapq.heappush(q, (cave[0][0], 0, 0))
    distance[0][0] = 0

    while q:
        cost, x, y = heapq.heappop(q)

        # 동굴 반대편에 도착한 경우,
        if x == N - 1 and y == N - 1:
            print(f'Problem {cnt}: {distance[x][y]}')
            break
        # 0 상, 1 하, 2 좌, 3 우
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N:  # 틀을 벗어나지 않고,
                total = cost + cave[nx][ny]
                if total < distance[nx][ny]:  # 새로운 경로가 기존 소모값 보다 작을때만 저장.
                    # print(f'nx : {nx}, ny : {ny}, distance[nx][ny] : {total}')
                    distance[nx][ny] = total
                    heapq.heappush(q, (distance[nx][ny], nx, ny))
        #             print(q)
        # print()


while True:
    N = int(input())
    if N == 0:
        break

    distance = [[INF] * N for _ in range(N)]
    cave = [list(map(int, input().split())) for _ in range(N)]
    dijikstra()
    cnt += 1
