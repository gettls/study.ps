from itertools import permutations


def solution(n, data):
    case = []
    friend = ["A", "C", "J", "M", "N", "F", "R", "T"]

    for p in permutations(friend, 8):
        case.append(p)

    parse = case
    for d in data:
        a, b = d[0], d[2]
        sign = d[3]
        interval = int(d[4])

        if sign == "=":
            result = []
            for c in parse:
                if abs(c.index(a) - c.index(b)) == 1:
                    result.append(c)
            parse = result

        elif sign == ">":
            result = []
            for c in parse:
                if abs(c.index(a) - c.index(b)) > interval + 1:
                    result.append(c)
            parse = result

        else:
            result = []
            for c in parse:
                if abs(c.index(a) - c.index(b)) <= interval:
                    result.append(c)
            parse = result

    answer = len(parse)
    return answer


print(solution(2, ["N~F=0", "R~T>2"]))

# {N,F}, A, C, J, M,
# R, T < 3

# N F //
# R + + T + + + + 2칸
# R + T + + + + + 1칸
# R T + + + + + + 0칸

# R + + + + + T +
# R + + + + + + T
