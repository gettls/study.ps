def solution(clothes):
    result = 1
    type_c = []

    for w in clothes:
        for i in range(1, len(w)):
            type_c.append(w[1])

    type_c_set = set(type_c)

    for i in type_c_set:
        result *= (type_c.count(i) + 1)

    answer = result - 1
    return answer

