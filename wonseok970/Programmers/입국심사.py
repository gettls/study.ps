n = 6
times = [7, 10]


# 1, 60

def solution(n, times):
    s, e = 1, max(times) * n
    while s <= e:
        # 심사하는데 걸린 시간
        mid = (s + e) // 2
        people = 0

        for t in times:
            people += mid // t
            # 심사를 다 받지않아도 n명 이상 심사가 될 경우
            if people >= n:
                break
        # 심사한 사람이 기준치 보다 많거나 같다면(정답이라면),
        if people >= n:
            answer = mid
            # 시간을 줄인다.
            e = mid - 1
        # 심사한 사람이 기준치 보다 적다면(시간이 부족하다면),
        else:
            # 시간을 늘인다.
            s = mid + 1

    return answer
