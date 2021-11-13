# 포트의 개수
n = int(input())

# 매칭
match = [0] + list(map(int, input().split())) + [0]

# [1,4] [2,2] [3,6] [4,3] [5,1] [6,5]
#  x     x     x     o     x     x

# 이전 번호의 포트가 n 이라면, 그 다음 번호의 포트는 무조건 n보다 커야한다.
# 따라서 처음에 연결포트가 가장 작은 포트를 찾는다.
# match = 4, 2, 6, 3, 1, 5
# s = 1, e = 6, mid = 3
# index = 4
#

s, e = 1, len(match) - 2
max_port = 0

# [3,2] [4,9]

def port(match, mid):
    index = 0
    cnt = 1
    for i in range(1, len(match)-1):
        index += 1
        if match[i] == mid:
            break
    print('index:', index)

    for i in range(index, len(match)-1): # 1, 2, 3, 4, 5
        if i == len(match)-2:
            if match[i] > mid:
                cnt += 1
        if match[i] > mid:
            if mid < match[i + 1] < match[i]:
                cnt += 1
                mid = match[i+1]
            elif mid < match[i] < match[i+1]:
                cnt += 1
                mid = match[i]


    print('cnt',cnt)
    return cnt


while s <= e:
    mid = (s + e) // 2
    print('s,e,mid: ',s, e, mid)
    max_port = port(match, mid)

    if max_port > mid:
        print(max_port)
        e = mid - 1
    else:
        print(max_port)
        s = mid + 1

print(max_port)
