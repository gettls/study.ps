import sys
from collections import deque

test_case = int(input())

for _ in range(test_case):
    reverse = False

    # 수행할 함수
    p = str(sys.stdin.readline())

    # 배열의 수
    n = int(sys.stdin.readline())

    # 리스트 입력
    x = deque(eval(input()))

    for i in p:
        if i == 'R':
            reverse = not reverse
        elif i == 'D':
            if len(x) <= 0:
                print('error')
                break
            # 뒤집혔을 때
            if reverse:
                x.pop()
            # 뒤집히지 않았을 때
            else:
                x.popleft()
    else:
        if reverse:
            x.reverse()
        print(str(list(x)).replace(' ', ''))



