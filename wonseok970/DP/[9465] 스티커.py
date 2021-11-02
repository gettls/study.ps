T = int(input())
dp = [0]

for j in range(T):
    sticker = []
    n = int(input())
    for i in range(2):
        sticker.append(list(map(int, input().split())))

    sticker[0][1] += sticker[1][0]
    sticker[1][1] += sticker[0][0]

    for i in range(2, n):
        sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2])
        sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2])

    print(max(sticker[0][n - 1], sticker[1][n - 1]))

#       0   1   2   3   4
# 0 // [50] 10 [100] 20  40
# 1 //  30 [50]  70  10 [60]
# 50, 40, 200, 130, 250
# 30, 100, 110, 210, 190

# refactor