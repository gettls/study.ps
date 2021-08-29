def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()
    result1, result2 = [], []
    inter_len, union_len = 0, 0

    for i in range(len(str1) - 1):
        get = str1[i:i + 2]
        if get.isalpha():
            result1.append(str1[i:i + 2])
        else:
            continue
    for i in range(len(str2) - 1):
        get = str2[i:i + 2]
        if get.isalpha():
            result2.append(str2[i:i + 2])
        else:
            continue

    print(result1, result2)

    if len(result2) == 0:
        return 65536

    # intersection
    inter = set(result1) & set(result2)
    # union
    union = set(result1) | set(result2)

    for i in inter:
        inter_len += min(result1.count(i), result2.count(i))
    for i in union:
        union_len += max(result1.count(i), result2.count(i))

    answer = inter_len / union_len
    return int(answer * 65536)


print(solution("FRANCE", "french"))
