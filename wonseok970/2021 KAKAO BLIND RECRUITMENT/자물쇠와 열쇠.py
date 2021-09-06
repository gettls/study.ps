def rotation_clock(arr_key):
    return list(zip(*arr_key[::-1]))


def check(arr_key, M, N):
    for i in range(N):
        for j in range(N):
            if arr_key[M + i][M + j] != 1:
                return False
    return True


def solution(key, lock):
    M, N = len(key), len(lock)

    extra = [[0] * (M * 2 + N) for _ in range(M * 2 + N)]

    for i in range(N):
        for j in range(N):
            extra[M + i][M + j] = lock[i][j]

    next_key = key
    for _ in range(4):
        next_key = rotation_clock(next_key)
        for x in range(1, M + N):
            for y in range(1, M + N):
                # 열쇠 넣기
                for i in range(M):
                    for j in range(M):
                        extra[x + i][y + j] += next_key[i][j]

                if check(extra, M, N):
                    return True

                # 열쇠 뺴기
                for i in range(M):
                    for j in range(M):
                        extra[x + i][y + j] -= next_key[i][j]

    return False
