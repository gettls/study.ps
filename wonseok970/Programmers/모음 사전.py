# A ... AAAAE AAAAI AAAAO AAAAU
# AAAE AAAEA AAAEE AAAEI AAAEO AAAEU
# AAE AAEA AAEE AAEI AAEO AAEU
# AE AEA AEE AEI AEO AEU

def solution(word):
    dic = []

    def add(s):
        if len(s) == 6:
            return
        dic.append(s)

        for i in word:
            # print('#2')
            # print(s + i)
            add(s + i)

    for i in word:
        # print('#1')
        # print(i)
        add(i)

    return dic.index(word) + 1


print(solution('A'))
