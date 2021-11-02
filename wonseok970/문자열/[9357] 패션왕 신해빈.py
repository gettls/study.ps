T = int(input())

while T:
    result = 1
    n = int(input())
    type_c = []
    for _ in range(n):
        a, b = input().split()
        type_c.append(b)
        type_c_set = list(set(type_c))

    for i in range(len(type_c_set)):
        # 착용하지 않는 경우 + 1
        result *= (type_c.count(type_c_set[i]) + 1)

    result -= 1
    print(result)
    T -= 1

# [ face, face, face ]
# [ face ]

# 1. mask / 2. sun / 3. maekup / 4. x


# 1. hat sun / hat x / turban sun / turban x / head sung
# refactor