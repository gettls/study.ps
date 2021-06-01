n = int(input())
number = list(map(int, input().split()))
number.sort()

m = int(input())
target_number = list(map(int, input().split()))


def bn_srch(start, end, array, target):
    if start > end:
        return False

    mid = (start + end) // 2
    if number[mid] == target:
        return True
    elif number[mid] < target:
        start = mid + 1
    else:
        end = mid -1
    return bn_srch(start, end, array, target)


for i in range(m):
    result = bn_srch(0, n - 1, number, target_number[i])
    if result:
        print(1)
    else:
        print(0)

