# # 나무의 수, 나무의 길이
# n, m = map(int, input().split())
#
# tree = list(map(int, input().split()))
#
# start = 1
# end = max(tree)
# while start <= end:
#
#     mid = (start+end)//2
#     trees = 0
#     for i in tree:
#         if i >= mid:
#             trees += i - mid
#
#     if trees >= m:
#         start = mid + 1
#     else:
#         end = mid - 1
#
# print(end)

n, m = map(int, input().split())

tree = list(map(int,input().split()))

start = 1
end = max(tree)
while start <= end:
    mid = (start+end)//2
    trees = 0
    for i in tree:
        if i >= mid:
            trees += i - mid

    if trees >= m:
        start = mid + 1
    else:
        end = mid - 1

print(end)

# refactor