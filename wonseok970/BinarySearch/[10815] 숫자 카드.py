n = int(input())
card_list = list(map(int, input().split()))

m = int(input())
check_list = list(map(int, input().split()))

card_list.sort()


def bn_search(start, end, target, array):
    if start > end:
        return False
    mid = (start + end) // 2

    if array[mid] == target:
        return True
    elif array[mid] < target:
        return bn_search(mid + 1, end, target, array)
    else:
        return bn_search(start, mid - 1, target, array)


for i in range(m):
    v = bn_search(0, n - 1, check_list[i], card_list)
    if v:
        print(1, end=" ")
    else:
        print(0, end=" ")