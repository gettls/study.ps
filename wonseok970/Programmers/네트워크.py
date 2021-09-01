from collections import deque


def solution(n, computers):
    answer = 0
    visited = [0 for i in range(len(computers))]

    def bfs(i):
        q = deque()
        q.append(i)
        while q:

            i = q.popleft()
            visited[i] = 1

            for j in range(n):

                if computers[i][j] == 1 and not visited[j]:
                    q.append(j)
                    # print(q)

    for i in range(n):
        # 탐색이 시작 될 때, 방문하지 않았다면 bfs 탐색을 시작한다.
        if not visited[i]:
            bfs(i)
            # 탐색이 끝나면 하나의 트리탐색을 끝냈기 때문에 네트워크에 +1 해준다.
            answer += 1

    return answer


print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
