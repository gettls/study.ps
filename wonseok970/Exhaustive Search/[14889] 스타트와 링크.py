N = int(input())
from itertools import combinations

ability = []
power_list = []

for i in range(N):
    ability.append(list(map(int, input().split())))

min_value = 200

for i in range(0, N):
    for j in range(i + 1, N):
        team_power = ability[i][j] + ability[j][i]
        power_list.append(team_power)
# print(power_list)
# power_list.sort()

for i in range(len(power_list)-1):
    pw_gap = abs(power_list[i] - power_list[i+1])
    if pw_gap < min_value:
        min_value = pw_gap

print(list(combinations(power_list, N // 2)))

for a in combinations(power_list, N//2):
    print(sum(a))


print(power_list)
print(min_value)

# 1 2 3
# S12, S13, S23
# S21, S31, S32

# 1 3 6

# 13, 16, 36,

# S13, S16, S36
# S31, S61, S63

# 2 3 4
# S23, S24, S34
#


# 3, 6, 8 = 17

# 21 31 41 51 61 32 42 52 62 43 53 63 54 64 65
#                     +
# 12 13 14 15 16 23 24 25 26 34 35 36 45 46 56
# [2, 3, 4, 5, 6, 4, 5, 6, 7, 6, 7, 8, 8, 9, 10]

# 1 2 3 4 5 6
# 123 124 125 126
# 234 235 236
# 345 346
# 456