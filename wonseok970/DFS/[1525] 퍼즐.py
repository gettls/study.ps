from collections import deque


def bfs():
    q = deque()
    q.append(puzzle)
    visited[puzzle] = 0

    while q:
        # 최종 결과가 get_p 와 같다면
        get_p = q.popleft()

        if get_p == '123456780':
            return visited[get_p]

        s = str(get_p)
        index_0 = get_p.find('0')

        # 3 X 3 배열의 좌표 찾기 - 문자열의 인덱스 값을 통해서
        # (0, 2)
        tx = index_0 // 3  # 2 // 3 = 0
        ty = index_0 % 3  # 2 % 3 = 2

        for i in range(4):
            nx = tx + dx[i]
            ny = ty + dy[i]

            # 좌하상우로 움직인 좌표가 0보다는 크고 3보다는 작을 때,
            if 0 <= nx < 3 and 0 <= ny < 3:
                # 좌표를 인덱스값으로 변환
                index_move = nx * 3 + ny
                ts = list(s)

                # 움직이려는 값 '0' 과 조건 내에서 움직인 좌표[인덱스로 변환] 를 교체
                ts[index_0], ts[index_move] = ts[index_move], ts[index_0]
                # 문자열로 변환
                ts = ''.join(ts)

                # get_p 라는 key 값이 존재하지 않을 떄,
                if not visited.get(ts):
                    visited[ts] = visited[get_p] + 1
                    q.append(ts)

    # 찾지 못했을 때 [return visited[v] 하지 못했을 때]
    return -1


puzzle = ''
visited = dict()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(3):
    puz = list(map(str, input().split()))
    puz = ''.join(puz)
    puzzle += puz

print(bfs())

# 1 0 3
# 4 2 5
# 7 8 6
# 103 425 786
