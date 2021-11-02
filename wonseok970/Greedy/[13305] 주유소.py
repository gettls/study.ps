N = int(input())
dis = list(map(int, input().split()))
price = list(map(int, input().split()))
total = 0

for i in range(N - 1):
    if price[i] < price[i + 1]:
        price[i + 1] = price[i]

for i in range(N - 1):
    total += price[i] * dis[i]

print(total)

#   2   3   1
# 5   2   4   1
# 5*2 / 2*(3+1)
# refactor