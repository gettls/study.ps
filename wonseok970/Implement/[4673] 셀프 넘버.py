arr = []

for n in range(10000):
    n = str(n)
    result = 0

    result += int(n)
    for i in n:
        result += int(i)

    if result < 10000:
        arr.append(result)

for j in range(10000):
    if j not in arr:
        print(j)