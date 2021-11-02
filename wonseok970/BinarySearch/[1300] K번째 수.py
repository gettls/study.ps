# n = int(input())
# K = int(input())
# B = [0]
#
# for i in range(1, n+1):
#     for j in range(1, n+1):
#         B.append(i*j)
# B.sort()
#
# start = 1
# end = max(B)
#
# while start <= end:
#     mid = (start+end) // 2
#     print(start, mid, end)
#     if B[K] >= B[mid]:
#         start = mid + 1
#     else:
#         end = mid - 1
# print(start, mid, end)
# print(B[start], B[end])

# 1 2 3 4
# 2 4 6 8
# 3 6 9 12
# 4 8 12 16
# B = [ 1 2 2 3 3 4 6 6 9 ] 3/3
# B = [ 1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16 ] 4/4

# 0 1 2 3 4 5 6 7 8 9
# 1 2 3 4 5 6 7 8 9 10
# mid = 4
# target = 4
#
# s=4, e=9
# mid = 6
# s=4, e=8
# mid = 6
# s=4, e=7 ...
# s=4, e=5
# mid = 4
# s=5, e=5
# mid = 5
n = int(input())
k = int(input())
s, e = 1, k
while s <= e:
    m = (s + e) // 2
    cnt = 0
    for i in range(1, n + 1):
        cnt += min(n, m // i)
        print(cnt, n, m // i)
    print(" ")
    if cnt < k:
        s = m + 1
    else:
        e = m - 1
    print(s,e)
    print(" ")
print(s)

# refactor