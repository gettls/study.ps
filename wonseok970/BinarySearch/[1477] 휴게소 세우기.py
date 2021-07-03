N, M, L = map(int, input().split())

loc = [0] + list(map(int, input().split())) + [L]
loc.sort()

s = 0
e = L

while s <= e:
    mid = (s + e) // 2
    count = 0

    # print('s, e, mid =', s, e, mid)

    for i in range(1, len(loc)):
        if loc[i] - loc[i - 1] > mid:
            count += (loc[i] - loc[i - 1] - 1) // mid  # 휴게소 사이의 설치가능한 개수
    # print('count', count)

    if count > M:  # 휴게소 사이의 설치가능한 개수가 M을 넘는다면,
        # print('decrease\n')
        s = mid + 1  # 간격을 늘린다 [ 설치가능 개수 감소 ]

    else:
        # print('increase\n')
        get = mid  # 휴게소 사이의 설치가능한 개수가 M을 넘지 못한다면,
        e = mid - 1  # 간격을 줄인다 [ 설치가능 개수 증가 ]

print(get)