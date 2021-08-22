T = int(input())


def bs_search(note, num):
    s = 0
    e = len(note_1) - 1

    while s <= e:
        mid = (s + e) // 2

        if num == note_1[mid]:
            return 1

        elif num > note_1[mid]:  # 찾으려는 값이 임의의 note_1의 mid 인덱스 값 보다 크다면
            s = mid + 1

        else:  # 찾으려는 값이 임의의 note_1의 mid 인덱스 값 보다 작거나 같다면,
            e = mid - 1

    return 0


for _ in range(T):
    N = int(input())
    note_1 = sorted(list(map(int, input().split())))  # [1,2,3,4,5]

    M = int(input())
    note_2 = list(map(int, input().split()))  # [1,3,7,9,5]

    for n in note_2:
        print(bs_search(note_1, n))
