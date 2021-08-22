M, N = map(int, input().split())

snack = list(map(int, input().split()))

s = 0
e = max(snack)

while s <= e:
    cnt = 0
    mid = (s + e) // 2

    for i in snack:  # 임의의 길이로 과자의 길이를 나누었을때 나오는 개수가,
        cnt += i // mid

    if cnt >= M:  # 개수가 아이들의 수 보다 크거나 같을 때,
        s = mid + 1  # 나누는 길이를 증가시킨다
        result = mid
    else:
        e = mid - 1

print(result)
