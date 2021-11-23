from itertools import permutations

s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"


def solution(s):
    answer = []
    s = s[2:-2]
    s = s.split("},{")
    s.sort(key = len)

    for index in s:
        split_i = index.split(",")

        for s_i in split_i:
            if int(s_i) not in answer:
                answer.append(int(s_i))

    return answer

