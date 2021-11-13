# 1. 4명
# 2. 3명
# 3. 7명


# 군부대의 증원, 감원
# " 1ia " = i번 부대에 a 명을 증,감한다는 뜻


# 군번 i번의 군인이 어떤 부대에 배치 받았는가
# " 2i "
# i번 군인이 몇 번 부대에 배치 받았는지를 출력한다.

N = int(input())

army = list(map(int, input().split()))
order = []

M = int(input())

for _ in range(M):
    order.append((tuple(map(int, input().split()))))

print(army)
print(order)