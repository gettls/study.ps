# lower bound

def lower_bound(connect, p):
    s = 0
    e = len(connect) - 1

    while s <= e:
        mid = (s + e) // 2

        if connect[mid] < p:  # 임의의 인덱스값이 p보다 작다면,
            s = mid + 1  # 시작 값을 증가
        else:
            e = mid - 1

    return s  #


# 6
# 4 2 6 3 1 5
# [2,6]
# [2,3]
# [1,3]
# [1,3,5]

n = int(input())
port = list(map(int, input().split()))
connect = []

for p in port:
    # connect 이 비어있거나, connect 의 마지막 원소가 p보다 작으면, p를 추가
    if not connect or connect[-1] < p:
        connect.append(p)

    # p가 connect 의 마지막 원소보다 작다면, lower bound 의 값에 p를 넣는다
    else:
        connect[lower_bound(connect, p)] = p

# print(connect)
print(len(connect))
