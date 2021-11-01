while True:
    sentence = input()
    if sentence == '.':
        break
    sentence_get = []
    answer = True

    for i in sentence:
        # 괄호를 찾으면 기록
        if i == "(" or i == "[":
            sentence_get.append(i)
        # 상반되는 기호를 찾았을 때,
        elif i == ")":
            # 기록이 없다면 대칭 X
            if len(sentence_get) == 0:
                answer = False
                break
            # 가장 마지막 기록이 상반되는 기호의 대칭이라면 O
            if sentence_get[-1] == "(":
                sentence_get.pop()
            else:
                answer = False
                break

        elif i == "]":
            # 기록이 없다면 대칭 X
            if len(sentence_get) == 0:
                answer = False
                break
            # 가장 마지막 기록이 상반되는 기호의 대칭이라면 O
            if sentence_get[-1] == "[":
                sentence_get.pop()
            else:
                answer = False
                break
        # True and True
        if answer and not sentence_get:
            print("yes")
        else:
            print("no")

# refactor