from collections import deque

board = [[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]


def solution(board):
    def check(cd, cnt):
        if cd not in visited:
            q.append([cd, cnt])
            visited.append(cd)

    n = len(board)
    visited = [[0, 0, 0, 1]]
    q = deque([])

    q.append([[0, 0, 0, 1], 0])

    while q:
        cd, cnt = q.popleft()
        x1, y1, x2, y2 = cd

        # 가로로 도착 (n-1, n-2, n-1, n-1)
        if x1 == n - 1 and y1 == n - 2 and x2 == n - 1 and y2 == n - 1:
            return cnt

        # 세로로 도착 (n-2, n-1, n-1, n-1)
        if x1 == n - 2 and y1 == n - 1 and x2 == n - 1 and y2 == n - 1:
            return cnt

        cnt += 1

        # 가로
        if x1 == x2:
            # ->
            if y2 + 1 < n and board[x2][y2 + 1] == 0:
                check([x1, y1 + 1, x2, y2 + 1], cnt)
            # <-
            if 0 <= y1 - 1 and board[x1][y1 - 1] == 0:
                check([x1, y1 - 1, x2, y2 - 1], cnt)
            # 상방, 우상방회전, 좌상방회전
            if x1 - 1 >= 0 and board[x1 - 1][y1] == 0 and board[x2 - 1][y2] == 0:
                check([x1 - 1, y1, x2 - 1, y2], cnt)
                check([x1 - 1, y1 + 1, x2, y2], cnt)
                check([x2 - 1, y2 - 1, x1, y1], cnt)
            # 하방, 우하방회전, 좌하방회전
            if x1 + 1 < n and board[x1 + 1][y1] == 0 and board[x2 + 1][y2] == 0:
                check([x1 + 1, y1, x2 + 1, y2], cnt)
                check([x2, y2, x1 + 1, y1 + 1], cnt)
                check([x1, y1, x2 + 1, y2 - 1], cnt)

        # 세로
        elif y1 == y2:
            # 하방
            if x2 + 1 < n and board[x2 + 1][y2] == 0:
                check([x1 + 1, y1, x2 + 1, y2], cnt)
            # 상방
            if 0 <= x1 - 1 and board[x1 - 1][y1] == 0:
                check([x1 - 1, y1, x2 - 1, y2], cnt)
            # 좌, x2y2축으로 좌회전, x1y1축으로 좌회전
            if 0 <= y1 - 1 and board[x1][y1 - 1] == 0 and board[x2][y2 - 1] == 0:
                check([x1, y1 - 1, x2, y2 - 1], cnt)
                check([x1 + 1, y1 - 1, x2, y2], cnt)
                check([x2 - 1, y2 - 1, x1, y1], cnt)
            # 우, x2y2축으로 우회전, x1y1축으로 우회전
            if y1 + 1 < n and board[x1][y1 + 1] == 0 and board[x2][y2 + 1] == 0:
                check([x1, y1 + 1, x2, y2 + 1], cnt)
                check([x2, y2, x1 + 1, y1 + 1], cnt)
                check([x1, y1, x2 - 1, y2 + 1], cnt)


print(solution(board))
