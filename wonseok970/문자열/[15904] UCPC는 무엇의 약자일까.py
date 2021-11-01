lst = input()
result = ''
cnt = 0

for word in lst:
    if word == 'U' and cnt == 0:
        result += word
        cnt += 1
    if word == 'C' and cnt == 1:
        result += word
        cnt += 1
    if word == 'P' and cnt == 2:
        result += word
        cnt += 1
    if word == 'C' and cnt == 3:
        result += word
        cnt += 1

if result == 'UCPC':
    print('I love UCPC')
else:
    print('I hate UCPC')

# UUUCUPUC
# refactor