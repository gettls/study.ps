n = int(input())
log = []

for i in range(n):
    a, b = input().split()
    if b == 'enter':
        log.append(a)
    elif b == 'leave':
        log.remove(a)

log.sort(reverse=True)

for l in log:
    print(l)

# enter_log = [ baha, askar, artem, baha ]
# leave_log = [ baha ]

# 5
# Baha enter
# Askar enter
# Baha leave
# Artem enter
# Baha enter
