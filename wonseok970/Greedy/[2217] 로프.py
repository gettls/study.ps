N = int(input())
rope = []
max_ = 0

for _ in range(N):
    rope.append(int(input()))

rope.sort(reverse=True)

for i in range(1, N + 1):
    x = rope[i-1] * i
    if max_ <= x:
        max_ = x

print(max_)
