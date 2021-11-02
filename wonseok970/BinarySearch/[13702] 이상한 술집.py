N, K = map(int, input().split())

juice = []
for i in range(N):
    juice.append(int(input()))
juice.sort()

s = 0
e = max(juice)

while s <= e:
    mid = (s + e) // 2
    count = 0
    left = 0
    for i in range(len(juice)):
        count += juice[i] // mid
        left += juice[i] % mid
    # print('s, e, mid, count left', s, e, mid, count, left)
    if count >= K:  # 나눈 몫이 사람수보다 많다면,
        # print('increase\n')
        get = mid
        s = mid + 1  # 몫의 양을 늘린다.

    else:  # 나눈 몫이 사람수보다 적다면,
        # print('decrease\n')

        e = mid - 1  # 몫의 양을 줄인다.

print(get)

# refactor