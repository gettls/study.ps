from itertools import combinations
from collections import Counter


def solution(orders, course):
    answer = []
    for c in course:  # 조합하기 위한 수 추출
        get = []
        for order in orders:
            for i in combinations(order, c):  # 손님들의 주문 조합
                res = ''.join(sorted(i))  # 문자열로 변환
                get.append(res)
        sorted_get = Counter(get).most_common()
        # print(sorted_get)
        for order, cnt in sorted_get:
            if cnt > 1 and cnt == sorted_get[0][1]:  # 가장 많이 선택된 메뉴 횟수
                answer.append(order)

    answer.sort()

    return answer

# ['AB', 'AC', 'AF', 'AG', 'BC', 'BF', 'BG', 'CF', 'CG', 'FG', 'AC', 'CD', 'CE', 'DE', 'AC', 'AD', 'AE', 'CD', 'CE', 'DE', 'BC', 'BF', 'BG', 'CF', 'CG', 'FG', 'AC', 'AD', 'AE', 'AH', 'CD', 'CE', 'CH', 'DE', 'DH', 'EH']
# ['ABC', 'ABF', 'ABG', 'ACF', 'ACG', 'AFG', 'BCF', 'BCG', 'BFG', 'CFG', 'CDE', 'ACD', 'ACE', 'ADE', 'CDE', 'BCF', 'BCG', 'BFG', 'CFG', 'ACD', 'ACE', 'ACH', 'ADE', 'ADH', 'AEH', 'CDE', 'CDH', 'CEH', 'DEH']
# ['ABCF', 'ABCG', 'ABFG', 'ACFG', 'BCFG', 'ACDE', 'BCFG', 'ACDE', 'ACDH', 'ACEH', 'ADEH', 'CDEH']
