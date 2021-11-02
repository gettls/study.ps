N, M, B = map(int, input().split())

land = [list(map(int, input().split())) for _ in range(N)]
h, n_block, d_block, result_h = 0, 0, 0, 0
min_time = 1000000000

for i in range(257):
    n_block, d_block = 0, 0
    for j in range(N):
        for k in range(M):
            if land[j][k] <= i:
                n_block += i - land[j][k]
            else:
                d_block += land[j][k] - i

    if d_block + B >= n_block:
        if min_time > (d_block * 2) + n_block:
            min_time = (d_block * 2) + n_block
            if result_h < i:
                result_h = i

print(min_time, result_h)
