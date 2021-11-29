import heapq


def solution(jobs):
    jobs.sort(key=lambda x: x[1])
    heap = []
    start, end, result, i = -1, 0, 0, 0

    while i < len(jobs):
        for j in jobs:
            if start < j[0] <= end:
                heapq.heappush(heap, [j[1], j[0]])

        if len(heap) > 0:
            get = heapq.heappop(heap)
            start = end  # 이전의 종료시간
            end += get[0]  # 현재 작업이 끝난 시점
            result += (end - get[1])  # 종료시간 - 시작시간 = 총 처리시간

            i += 1  # 작업 처리 횟수

        else:  # 처리할 작업이 없을경우,
            end += 1  # 작업 종류 후 현재 시간을 1씩 늘린다.

    return result//len(jobs)

# def solution(jobs):
#     min_val = int(1e9)
#     get = permutations(jobs, len(jobs))
#
#     for g in get:
#         cnt = 0
#         result = []
#
#         for j in g:
#             if cnt == 0:
#                 s, w = j
#
#                 end_time = (s + w)  # 3
#                 result.append(w)
#             else:
#                 s, w = j
#                 gap = abs(end_time - s)
#                 total = gap + w
#                 result.append(total)
#
#                 end_time = (s + total)
#             cnt += 1
#
#         min_val = min(min_val, sum(result) // len(g))
#
#     return min_val
#
# print(solution(jobs))

# a, b, c

# a - b - c
# a - c - b
# b - a - c
# b - c - a
# c - a - b
# c - b - a

# for j in jobs:
#     s, w = j
#     print(s, w)
