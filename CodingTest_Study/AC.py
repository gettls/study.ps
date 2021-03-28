import sys
from collections import deque

test_case = int(input())

for _ in range(test_case):
    reverse = 1

    # 수행할 함수
    p = str(sys.stdin.readline())

    # 배열의 수
    n = int(sys.stdin.readline())

    # 리스트 입력
    x = deque(eval(input()))

    for i in p:
        if i == 'R':
            reverse *= -1
        elif i == 'D':
            if n <= 0:
                print('error')
                break
            # 뒤집혔을 때
            if reverse == -1:
                x.pop()
                n -= 1

            # 뒤집히지 않았을 때
            elif reverse == 1:
                x.popleft()
                n -= 1
    else:
        if reverse == -1:
            x.reverse()
        print(str(list(x)).replace(' ', ''))

