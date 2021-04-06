N = int(input())
lst = []
check = [[] for _ in range(N)]

# 0 ~ 9
result = [0] * 26
get = 0

for i in range(N):
    lst.append(input())

for i in range(N):
    for j in range(len(lst[i])):
        check[i].append(ord(lst[i][j]) - 65)

for i in range(N):
    j = len(lst[i]) - 1
    for ch in check[i]:
        result[ch] += 10 ** j
        j -= 1

result.sort()

max_num = 9
for i in range(25, -1, -1):
    get += result[i] * max_num
    max_num -= 1

print(get)
