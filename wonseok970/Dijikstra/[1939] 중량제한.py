from collections import deque

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]


for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

s, e = map(int, input().split())

min_, max_ = 1, 1000000000


def bfs(carry):
    queue = deque([s])
    visited = [0 for _ in range(N + 1)]
    visited[s] = 1

    while queue:
        s_node = queue.popleft()

        for n_node, w in graph[s_node]:
            if visited[n_node] == 0 and w >= carry:  # 옮기려는 중량 carry 가 다리의 중량제한 w 보다 작야야 한다
                # print(n_node, w, carry)
                visited[n_node] = 1
                queue.append(n_node)

    if visited[e] == 1:
        return True
    else:
        return False


result = 0
while min_ <= max_:
    mid = (min_ + max_) // 2

    if bfs(mid):
        # print(f'min:{min_}, max:{max_}, mid:{mid}')
        result = mid  # 종착지의 값이 visited 에 기록되었을 경우, 저장
        # visited 에 기록이 되었어도 수송가능한 최대의 중량값을 찾기 위함
        min_ = mid + 1
    else:
        max_ = mid - 1

print(result)
