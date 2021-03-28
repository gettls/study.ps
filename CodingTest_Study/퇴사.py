n = int(input())

t = [0]
p = [0]
# n + 1일 까지 계산합니다.
d = [0] * (n+2)
result = 0

for i in range(n):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)

# 2. DP (bottom-up) 수행
for i in range(1, n+2):
    for j in range(1, i):
        # 1) j 번째 날에서 일을 안하고 i 번째 날까지 온 경우(j < i)
        d[i] = max(d[i], d[j])

        # 2) j 번째 날에서 t[j] 기간 동안 일을하고 보상을 p[j] 받은 경우
        # 그 보상은 j + t[j] 날 받습니다.
        if j + t[j] == i:
            d[i] = max(d[i], d[j] + p[j])

    # 3) 최대값을 갱신해줍니다.
    result = max(result, d[i])

# 3. 출력
print(result)