import re
import sys

test_case = int(input())

for _ in range(test_case):
    get_list = []

    # 입력할 함수
    func = list(sys.stdin.readline())

    # 함수의 길이
    list_len = int(sys.stdin.readline())

    # 리스트 입력
    array = sys.stdin.readline()

    # 숫자만 추출
    numbers = list(map(int, re.findall("\d+", array)))

    for i in range(len(numbers)):
        get_list.append(numbers[i])

    for j in range(len(func)):
        if func[j] == 'R':
            get_list.reverse()
        elif func[j] == 'D':
            if len(get_list) <= 1:
                print('error')
                break
            else:
                del get_list[0]

    if len(get_list) > 1:
        print(list(get_list))
