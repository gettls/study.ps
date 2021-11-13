# 굴다리의 길이
N = int(input())

# 가로등의 개수
M = int(input())

# 가로등의 좌표
loc = [0] + list(map(int, input().split())) + [N]

s = 0
e = N
res = 0


def getHeight(loc, mid):
    if loc[1] - loc[0] > mid:
        return 1
    if loc[-1] - loc[-2] > mid:
        return 1
    # 처음에 추가한 0과 N은 제외하고,
    for i in range(1, len(loc) - 2):
        if (loc[i + 1] - loc[i]) / 2 > mid:
            return 1
    return 0


while s <= e:
    mid = (s + e) // 2 # mid = 3
    if getHeight(loc, mid):
        s = mid + 1
    else:
        e = mid - 1
        res = mid # 높이를 줄이는 최소값만 저장

print(res)