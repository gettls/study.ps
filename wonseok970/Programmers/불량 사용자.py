from itertools import permutations


def check(p_ui, bi):
    for i in range(len(p_ui)):
        # 제재아이디와 응모자 아이디의 길이가 다를경우,
        if len(p_ui[i]) != len(bi[i]):
            return False

        for j in range(len(bi[i])):
            if bi[i][j] == '*':
                continue
            if p_ui[i][j] != bi[i][j]:
                return False
    return True


def solution(user_id, banned_id):
    result = []
    for p_ui in permutations(user_id, len(banned_id)):
        if check(p_ui, banned_id):
            p_ui = set(p_ui)
            if p_ui not in result:
                result.append(p_ui)

    return len(result)


