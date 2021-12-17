from collections import deque

nodeinfo = [[5, 3], [11, 5], [13, 3], [3, 5], [6, 1], [1, 3], [8, 6], [7, 2], [2, 2]]


# [[8, 6], [3, 5], [11, 5], [1, 3], [5, 3], [13, 3], [2, 2], [7, 2], [6, 1]]

def pre(sort_x, sort_y, answer):
    parent_node = sort_y[0]
    index = sort_x.index(parent_node)
    p_left = []
    p_right = []

    for i in range(1, len(sort_y)):
        # x좌표 의 값이 부모노드보다 작다면
        if sort_y[i][0] < parent_node[0]:  # 8
            p_left.append(sort_y[i])
        else:
            p_right.append(sort_y[i])

    answer.append(parent_node[2])

    # 자식 노드가 있을때
    if len(p_left) > 0:
        pre(sort_x[:index], p_left, answer)
    if len(p_right) > 0:
        pre(sort_x[index + 1:], p_right, answer)

    # 리프노드에 도착했을 때,
    return


def post(sort_x, sort_y, answer):
    parent_node = sort_y[0]
    index = sort_x.index(parent_node)
    p_left = []
    p_right = []

    for i in range(1, len(sort_y)):
        # x좌표 의 값이 부모노드보다 작다면
        if sort_y[i][0] < parent_node[0]:  # 8
            p_left.append(sort_y[i])
        else:
            p_right.append(sort_y[i])

    # 자식 노드가 있을때
    if len(p_left) > 0:
        post(sort_x[:index], p_left, answer)
    if len(p_right) > 0:
        post(sort_x[index + 1:], p_right, answer)
    answer.append(parent_node[2])
    return


def solution(nodeinfo):
    for i in range(len(nodeinfo)):
        nodeinfo[i].append(i + 1)

    sort_x = sorted(nodeinfo)
    sort_y = sorted(nodeinfo, key=lambda x: (-x[1], x[0]))
    pre_order = []
    post_order = []

    pre(sort_x, sort_y, pre_order)
    post(sort_x, sort_y, post_order)

    return [pre_order, post_order]
