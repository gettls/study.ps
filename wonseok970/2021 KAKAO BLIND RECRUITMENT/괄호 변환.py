p = input()


def solution(p):
    cnt = 0
    if p == "":
        return ""

    for i in range(len(p)):
        if p[i] == "(":
            cnt += 1
        elif p[i] == ")":
            cnt -= 1

        # 문자열 분리
        if cnt == 0:
            u = p[:i + 1]
            v = p[i + 1:]
            if check_right(u) is True:
                return u + solution(v)
            else:
                answer = "(" + solution(v) + ")" + reverse(u)
                return answer


def reverse(u):
    u = u[1:-1]
    result = ""
    for s in u:
        if s == "(":
            result += ")"
        elif s == ")":
            result += "("

    return result


def check_right(u):
    stack = []
    for s in u:
        if s == ")":
            if len(stack) == 0:
                return False
            get = stack.pop()
            if get == "(":
                continue
            elif get != "(":
                return False

        else:
            stack.append(s)

    return True


# print(solution(p))
