N = int(input())

hansu = 0

for i in range(1, N+1):
    if i <= 99:
        hansu += 1

    else:
        lst = list(map(int, str(i)))
        if lst[0] - lst[1] == lst[1] - lst[2]:
            hansu += 1

print(hansu)