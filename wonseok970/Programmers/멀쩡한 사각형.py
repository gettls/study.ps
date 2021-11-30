import math

W, H = 8, 12


def solution(W, H):

    return W*H - (W+H-math.gcd(W, H))

# def solution(W, H):
#     answer = W * H
#     cnt = 0
#
#     # Case1
#     if W == H:
#         result = W
#
#     # Case 2
#     else:
#         # 둘 다 짝수
#         if W % 2 == 0 and H % 2 == 0:
#             while 1:
#                 if W == 1 or H == 1:
#                     break
#                 else:
#                     W = math.ceil(W / 2)
#                     H = math.ceil(H / 2)
#                     cnt += 1
#             result = (max(W, H) * 2 ** cnt)
#
#         # 홀과 짝
#         elif (W + H) % 2 != 0:
#             while 1:
#                 if W == 1 or H == 1:
#                     break
#                 else:
#                     W = math.ceil(W / 2)
#                     H = math.ceil(H / 2)
#                     cnt += 1
#             result = (max(W, H) * (2 ** cnt)) + 2
#
#         # 홀과 홀
#         else:
#             while 1:
#                 if W == 1 or H == 1:
#                     break
#                 else:
#                     W = math.ceil(W / 2)
#                     H = math.ceil(H / 2)
#                     cnt += 1
#
#             result = (max(W, H) * (2 ** cnt)) - 1
#
#     return answer - result
#
#
# print(solution(W, H))


