from itertools import permutations


def calculate(pre_num, next_num, s):
    if s == "*":
        return pre_num * next_num
    if s == "-":
        return pre_num - next_num
    if s == "+":
        return pre_num + next_num


def solution(expression):
    start, end = 0, 0
    max_val = int(-1e9)
    sign = set()
    number = []

    for e in expression:
        if e == "-" or e == "*" or e == "+":
            sign.add(e)

    for i in range(len(expression)):
        if expression[i] == "-" or expression[i] == "*" or expression[i] == "+":
            number.append(int(expression[start:i]))
            number.append(expression[i])
            start = i + 1

        elif i == len(expression) - 1:
            number.append(int(expression[start:]))

    p_sign = list(permutations(sign, len(sign)))

    for s in p_sign:
        num_copy = number.copy()
        for ss in s:
            # 숫자 보관용 stack
            stack = []
            while len(num_copy) != 0:
                cons = num_copy.pop(0)
                if cons == ss:
                    # 기호 전 숫자, 기호 후 숫자
                    stack.append(calculate(stack.pop(), num_copy.pop(0), ss))
                else:
                    stack.append(cons)
            num_copy = stack
        max_val = max(max_val, abs(num_copy[0]))

    return max_val

# 300 - 6
# 294

# 50 * ( 6 - 3 ) * 2
# (50 * 3) * 2
# (150 * 2)
# 300

# (50 * 6) - 3 * 2
# 300 - (3 * 2)
# 294

# for n in number:
