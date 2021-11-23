from itertools import combinations

relation = [["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"],
            ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]


def solution(relation):
    col = len(relation[0])
    row = len(relation)

    candidates_key = []
    for i in range(1, col + 1):
        candidates_key.extend(combinations(range(col), i))

    unique = []
    for keys in candidates_key:
        tmp = [tuple([r[key] for key in keys]) for r in relation]

        # 유일성 검사 / 열의 길이와 tmp 의 길이가 같다면!?
        if len(set(tmp)) == row:
            flag = 1

            for u in unique:
                # 최소성 검사
                if set(u).issubset(set(keys)):
                    flag = 0
                    break

            if flag == 1:
                unique.append(keys)
    return len(unique)
