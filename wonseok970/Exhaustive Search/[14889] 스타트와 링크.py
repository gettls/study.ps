from itertools import combinations

N = int(input())

ability = []
player = [i for i in range(1, N+1)]
comb = list(combinations(player, N // 2))
min_val = 1e9

for i in range(N):
    ability.append(list(map(int, input().split())))


for team_a in comb:
    power_a, power_b = 0, 0
    for x in team_a:
        for y in team_a:
            power_a += ability[x-1][y-1]

    team_b = [i for i in range(1, N+1) if i not in team_a]

    for x in team_b:
        for y in team_b:
            power_b += ability[x-1][y-1]

    min_val = min(min_val, abs(power_a - power_b))

print(min_val)

# [2, 3, 4, 5, 6, 4, 5, 6, 7, 6, 7, 8, 8, 9, 10]