import sys

sys.setrecursionlimit(99999)

# 회사의 직원수, 최초의 칭찬 횟수
n, m = map(int, input().split())
get_id = [[] for i in range(100001)]
compliment = [0] * 100001


def dfs(v):
    for i in get_id[v]:
        compliment[i] += compliment[v]
        dfs(i)


# 직속 상사번호 입력
num_list = list(map(int, input().split()))

# 직원들의 번호
for i in range(n):
    if num_list[i] == -1:
        pass
    else:
        get_id[i].append(num_list[i] + 1)

# 직원번호, 칭찬의 수치 입력
for _ in range(m):
    i, w = list(map(int, input().split()))
    compliment[i - 1] = w

dfs(1)


for i in range(n):
    print(compliment[i], end=' ')

# refactor