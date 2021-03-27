import sys
from collections import deque

test_case = int(input())

for _ in range(test_case):
    dq = deque()
    dq_r = deque()
    reverse = 1
    del_count = 0

    # 수행할 함수
    p = sys.stdin.readline()

    # 배열의 수
    n = int(sys.stdin.readline())

    # 리스트 입력
    x = eval(input())

    for i in x:
        dq.append(i)

    for i in p:
        if n <= 0:
            error = 0
            break
        if i == 'R':
            reverse *= -1
        elif i == 'D':
            # 뒤집혔을 때
            if reverse == -1:
                dq.pop()
                n -= 1
            # 뒤집히지 않았을 때
            elif reverse == 1:
                dq.popleft()
                n -= 1

    if reverse == -1:
        for i in range(n):
            v = dq.pop()
            dq_r.append(v)
        print('[', end="")
        for i in range(n):
            if i == n - 1:
                print(dq[i], end='')
            else:
                print(dq[i], end=',')
        print(']')

    elif reverse == 1:
        print('[', end="")
        for i in range(n):
            if i == n - 1:
                print(dq[i], end='')
            else:
                print(dq[i], end=',')
        print(']')

    elif error == 0:
        print('error')
