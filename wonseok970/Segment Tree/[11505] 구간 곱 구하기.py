import sys

input = sys.stdin.readline


def prefixMul(node, start, end, left, right):
    # start 와 end 를 구간이 벗어날 경우 / [l, r] [s, e]
    if right < start or end < left:
        return 1

    # 합을 해야하는 l,r 구간이 s, e를 포함시키는 경우 / [l , [s, e] , r]
    if left <= start and end <= right:
        return tree[node]

    result = prefixMul(node * 2, start, (start + end) // 2, left, right) * prefixMul(node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return result % 1000000007


def update(node, start, end, index, val):
    # index 의 값이 [s, e] 의 범위를 벗어날 경우
    if index < start or end < index:
        return

    # c - l[b] -> 노드의 값에 변경할 값 c를 더해주고
    # 현재 노드의 값 l[b] 를 빼준다.
    if start == end:
        tree[node] = val
        return

    # update 해주려는 node 가 leaf 노드가 아닌 경우에는,
    # 자식 노드도 변경해주어야 한다.
    if start != end:  # start, end 가 같은 경우에 leaf node
        update(node * 2, start, (start + end) // 2, index, val)  # 왼쪽 자식
        update(node * 2 + 1, (start + end) // 2 + 1, end, index, val)  # 오른쪽 자식
        tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007


N, M, K = map(int, input().split())

list_ = []
tree = [0] * 3000000

for i in range(N):
    num = int(input())
    list_.append(num)
    update(1, 0, N-1, i, num)

for _ in range(M + K):
    # a = 1 일때,
    # b 번째 수를
    # c 로 바꾼다

    # a = 2 일때,
    # b ~ c 의 곱을 구한다
    a, b, c = map(int, input().split())

    if a == 1:
        b = b - 1
        list_[b] = c
        update(1, 0, N - 1, b, c)

    elif a == 2:
        # root node 에서 0 ~ 4 의 인덱스 중, left ~ right 인덱스의 합을 구한다
        print(prefixMul(1, 0, N - 1, b - 1, c - 1))


