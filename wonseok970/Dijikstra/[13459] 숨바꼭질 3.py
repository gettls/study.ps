from collections import deque

INF = 100001  # 100,000 까지의 거리
N, K = map(int, input().split())

# 시작점 N을 데크에 추가
q = deque()
q.append(N)
# N은 방문처리
check = [-1 for _ in range(100001)]
check[N] = 0

while q:
    now = q.popleft()  # 현재 위치를 pop
    if now == K:
        print(check[now])
        break
    # X-1
    if 0 <= now - 1 <= 100001 and check[now - 1] == -1:
        check[now - 1] = check[now] + 1
        q.append(now - 1)

    # 순간이동
    if 0 < now * 2 <= 100001 and check[now * 2] == -1:  # 현재의 점이 범위를 벗어나지 않고, 방문하지 않았을 때
        check[now * 2] = check[now]
        q.appendleft(now * 2)  # 순간이동은 선처리를 위하여 앞쪽에 데이터를 추가한다.

    # X+1
    if 0 <= now + 1 <= 100001 and check[now + 1] == -1:
        check[now + 1] = check[now] + 1
        q.append(now + 1)

