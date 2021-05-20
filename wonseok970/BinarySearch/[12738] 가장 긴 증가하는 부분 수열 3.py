from bisect import bisect_left
import sys

get = sys.stdin.readline

n = int(get())
lst = list(map(int, get().split()))
a = [lst[0]]


for x in lst:
    if a[-1] < x:
        a.append(x)
    else:
        a[bisect_left(a, x)] = x

print(len(a))