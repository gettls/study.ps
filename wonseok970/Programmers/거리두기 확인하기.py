from collections import deque

places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
          ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
          ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(a, b, maps):
    q = deque()
    q.append([a, b])
    visited = [[0] * 5 for _ in range(5)]
    visited[a][b] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < 5 and 0 <= ny < 5:
                if not visited[nx][ny]:
                    if maps[nx][ny] == 'P':
                        if abs(a - nx) + abs(b - ny) <= 2:
                            if maps[(nx + a) // 2][(ny + b) // 2] == 'X':
                                # print(nx, ny, a, b, maps[nx][ny])
                                # print(abs(i - nx) + abs(j - ny))
                                # for v in visited:
                                #     print(v)
                                # print()
                                pass
                            else:
                                return 0
                        else:
                            pass

                    elif maps[nx][ny] == 'O':
                        q.append([nx, ny])
                        visited[nx][ny] = 1
    # print("hi")
    return 1


def solution(places):
    answer = []

    for p in places:
        result = 1
        for i in range(5):
            for j in range(5):
                if p[i][j] == "P":
                    result *= bfs(i, j, p)
        answer.append(result)
    return answer

print(solution(places))