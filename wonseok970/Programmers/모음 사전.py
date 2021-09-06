def solution(table, languages, preference):
    result = [[] for _ in range(len(languages))]
    total = [0 for _ in range(len(table))]
    index = []
    max_value = 1e9
    dict_language = [5, 1, 3, 4, 2]
    table_language = ["SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"]

    for i in range(len(table)):
        table[i] = table[i].split(" ")
        table[i].reverse()

    for i in range(len(languages)):
        for j in range(len(table)):
            if languages[i] in table[j]:
                result[i].append((table[j].index(languages[i]) + 1) * preference[i])
                # print(result[i])
            else:
                result[i].append(0)
                # print(result[i])

    for j in range(len(table)):
        for i in range(len(result)):
            total[j] += result[i][j]

    max_ = max(total)

    for i in range(len(total)):
        if total[i] == max_:
            index.append(i)

    for i in index:
        max_value = min(dict_language[i], max_value)

    answer = table_language[dict_language.index(max_value)]

    return answer