import collections

N, K = map(int, input().split())
jwl = collections.deque([])
weight = []
total, max_val = 0

for i in range(N):
    jwl.append(list(map(int, input().split())))

for i in range(K):
    weight.append(int(input()))

for i in range(K):
    take = []
    jwl_list = sorted(jwl)
    for j in range(N):
        if weight[i] >= jwl_list[j][0]:
            take.append(jwl_list.pop(j))
            max_val = max(take[j][1])
    total += max_val




# refactor
# print(jwl[0][1], jwl[1][1], jwl[2][1])


