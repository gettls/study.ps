from collections import deque


def check(s):
    stack = []
    if len(s) == 1:
        return False

    for i in s:
        if i == "(" or i == "{" or i == "[":
            stack.append(i)

        else:
            if len(stack) == 0:
                return False

            if i == ")" and stack.pop() != "(":
                return False
            if i == "]" and stack.pop() != "[":
                return False
            if i == "}" and stack.pop() != "{":
                return False

    if len(stack) == 0:
        return True


def solution(s):
    s = deque(s)
    answer = 0

    for i in range(len(s)):
        s.rotate(-1)
        if check(s):
            answer += 1

    return answer


print(solution("{{{{{{{"))

# True
# False
# False
# True
# True
# False
