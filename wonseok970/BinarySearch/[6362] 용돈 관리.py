N, M = map(int, input().split())

money = [int(input()) for _ in range(N)]

s = max(money)
e = sum(money)
result = max(money)
# [100, 400, 300, 100, 500, 101, 400]
while s <= e:
    mid = (s+e) // 2
    get = mid
    cnt = 1

    for i in range(N):
        if get >= money[i]:  # 가진 돈이 소비금액보다 같거나 클 경우,
            get -= money[i]  # 소비

        else:  # 가진 돈이 소비금액보다 작을 경우,
            cnt += 1  # 출금 횟수 + 1
            get = mid  # 출금
            get -= money[i]  # 소비

        if cnt <= M:  # 출금 횟수가 M보다 적거나 같을 경우, 출금 금액을 줄인다
            e = mid - 1
            result = min(result, mid)
        else:
            s = mid + 1

print(result)