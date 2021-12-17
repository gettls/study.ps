from collections import deque

maps = [[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]


def solution(maps):
    answer = bfs(maps)
    return answer


def bfs(maps):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    length = len(maps)
    width = len(maps[0])

    q = deque()
    q.append([0, 0])
    visited = [[-1] * width for _ in range(length)]
    visited[0][0] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < length and 0 <= ny < width:
                if maps[nx][ny] == 1 and visited[nx][ny] == -1:
                    q.append([nx, ny])
                    visited[nx][ny] = visited[x][y] + 1
    return visited[length - 1][width - 1]


print(solution(maps))

# from collections import deque
#
# maps = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]
#
# def solution(maps):
#     return bfs(maps)
#
#
# def bfs(maps):
#     dy, dx = [1,-1,0,0], [0,0,1,-1]
#     dist = [[-1] * len(maps[0]) for _ in range(len(maps))]
#     dist[0][0] = 1
#     q = deque([(0, 0)])
#     while q:
#         cy, cx = q.popleft()
#         for d in range(4):
#             ny, nx = cy + dy[d], cx + dx[d]
#             if 0 <= ny < len(maps) and 0 <= nx < len(maps[0]):
#                 if dist[ny][nx] == -1 and maps[ny][nx] == 1:
#                     dist[ny][nx] = dist[cy][cx] + 1
#                     q.append((ny, nx))
#
#     print(dist)
#     return dist[-1][-1]
#
# print(solution(maps))
