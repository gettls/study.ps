from itertools import combinations

L, C = map(int, input().split())

password = list(map(str, input().split()))
password.sort()
vow = ['a','e','i','o','u']

result = []

for code in list(combinations(password, L)):
    vow_cnt, cos_cnt = 0, 0
    for word in code:
        if word in vow:
            vow_cnt += 1
        else:
            cos_cnt += 1

    if vow_cnt > 0 and cos_cnt > 1:  # 모음 1개이상, 자음 2개 이상일때,
        result.append("".join(code))

for get in result:
    print(get)


# a c i s t w