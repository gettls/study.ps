N = int(input())
M = int(input())
button = []
broken = list(map(int, input().split()))
channel = 100

if M > 0:
    for i in range(10):
        if i in broken:
            continue
        else:
            button.append(str(i))

# 기본 채널에서 선택 채널까지 움직이는 경우
min_cnt = abs(N - channel)


for num in range(1000001):  # 5455
    num = str(num)
    for i in range(len(num)):
        if num[i] not in button:  # num 에 사용 불가능한 버튼이 있을 경우,
            break

        elif i == len(num) - 1:  # 버튼 검증이 끝났을 때,
            # |목푯값-채널값| + 채널 자릿 수
            min_cnt = min(min_cnt, abs(N - int(num)) + len(str(num)))

print(min_cnt)


# for i in range(len(N)):
#     if int(N[i]) in button:
#         print(N[i])
#         lst.append(int(N[i]))
# print(lst)



# 5450 4
# 5457 11


# 5455 4
# 5456 5
# 5457 6

# 5459 4
# 5458 5
# 5457 6

#
# for i in list(permutations(button, 4)):
#     # print(i)
#     for j in range(4):
#         if i[j] != int(N[j]):
#             break
#         else:
#             print(i)
#         # if i[j] == int(N[j]):
#         #     print(i)



# min(100 에서 얼마나 걸리는가, 버튼으로 움직이는데 걸리는 cnt)

# 6457
# 6 8 9

# 5999
# 7000

# 1. 1 작은 5로 시작
# 2. 1 큰 7로 시작


# 6457
# 5 7

# 6