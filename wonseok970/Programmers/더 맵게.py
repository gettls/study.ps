import heapq


def solution(scoville, K):
    q = []
    cnt = 0
    for s in scoville:
        heapq.heappush(q, s)

    while q[0] < K:
        try:
            min_s = heapq.heappop(q)
            next_s = heapq.heappop(q)
            mixed = min_s + next_s * 2

            heapq.heappush(q, mixed)
        except IndexError:
            return -1

        cnt += 1

    return cnt


