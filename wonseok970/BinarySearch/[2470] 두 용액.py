# 산성, 알칼리

n = int(input())

lst = list(map(int, input().split()))
lst.sort()

start = 0
end = n - 1
MIN_VALUE = (lst[start] + lst[end])
M_start = start
M_end = end

while start < end:
    val = lst[start] + lst[end]

    if abs(MIN_VALUE) > abs(val):
        M_start = start
        M_end = end
        MIN_VALUE = abs(val)
        if val == 0:
            break

    # 양 끝 수의 합이 0을 초과하면 end 값이 크다는 뜻,
    if val > 0:
        end -= 1
    # 양 끝 수의 합이 0미만이라면 lst[start]값이 작다는 뜻
    else:
        start += 1

print(lst[M_start], lst[M_end])

# refactor