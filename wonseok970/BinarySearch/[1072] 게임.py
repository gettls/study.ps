X, Y = map(int, input().split())

Z = int(Y * 100 / X)


if Z >= 99:
    print(-1)

else:
    s = 0
    e = 1000000000

    while s <= e:
        mid = (s + e) // 2

        nx = X + mid
        ny = Y + mid
        nz = int(ny * 100 / nx)

        # print()
        # print(nz, Z)

        if nz <= Z:  # 횟수를 늘린 승률이 기존 승률보다 낮거나 같다면
            s = mid + 1
            # print(s, e, mid, '1')
        else:
            e = mid - 1
            result = mid
            # print(s, e, mid, '2')

    print(result)
