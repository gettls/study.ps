N = int(input())
lst = [input() for _ in range(N)]
cnt = 0

for word in lst:
    # 홀수의 경우
    if len(word) % 2 != 0:
        continue
    else:
        stack = [word[0]]

    for i in range(1, len(word)):
        if len(stack) == 0:
            stack.append(word[i])
            continue
        if stack[-1] == word[i]:
            stack.pop()
        else:
            stack.append(word[i])
    # 짝을 모두 찾았을 떄,
    if len(stack) == 0:
        cnt += 1
    else:
        continue

print(cnt)
