T = int(input())

for _ in range(T):
    # N은 1~N의 책, M은 서강대학교 학부생 수
    N, M = map(int, input().split())

    for j in range(M):
        ai, bi = map(int, input().split())