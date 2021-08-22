T = int(input())


def bs_search(list_, index_a):
    s = 0
    e = len(list_) - 1

    result = 0

    while s <= e:
        mid = (s + e) // 2
        if list_[mid] < index_a:  # A의 값이 B의 값 보다 크다면 [성공]
            s = mid + 1  # 인덱스값 +
            result = mid + 1
        else:
            e = mid - 1  # 인덱스값 -

    return result


for _ in range(T):
    A, B = map(int, input().split())

    list_A = sorted(list(map(int, input().split())))
    list_B = sorted(list(map(int, input().split())))
    cnt = 0

    for a in list_A:
        cnt += bs_search(list_B, a)

    print(cnt)
