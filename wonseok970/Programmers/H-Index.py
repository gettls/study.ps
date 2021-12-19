def solution(citations):
    citations.sort()
    s = 0
    e = max(citations)

    while s <= e:
        mid = (s + e) // 2
        cnt = 0

        if max(citations) == 0:
            return 0

        for c in citations:
            if c >= mid:
                cnt += 1

        if cnt < mid:
            e = mid - 1
        else:
            result = mid
            s = mid + 1

    return result