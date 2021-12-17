# 33.010
# + 0.011
# 33.020

s = [
    "2016-09-15 01:00:04.002 2.0s",
    "2016-09-15 01:00:07.000 2s"
]


# 총 시간 구하기
def get_time(time):
    # 초를 기준으로 시간은 3600, 분은 60을 곱해준다.
    hour = int(time[:2]) * 3600
    minute = int(time[3:5]) * 60
    second = int(time[6:8])
    millisecond = int(time[9:])

    # millisecond 를 기준을 맞춰 total 값에 1000을 곱해준다.
    total = (hour + minute + second) * 1000 + millisecond

    return total


# 시작시간 구하기
def get_start_time(time, waste_time):
    # 처리시간은 초단위이므로 ms 단위로 연산해준다.
    int_w_time = int(float(waste_time[:-1]) * 1000)

    # 입력 받은시간 기준으로 처리된 시간을 뺴준다.
    return get_time(time) - int_w_time + 1


def solution(s):
    s_time = []
    e_time = []
    answer = 0

    for test in s:
        test = test.split(" ")
        time = test[1]
        waste_time = test[2]

        # ms 단위로 시작시간와 종료시간을 구하여 배열에 추가한다.
        s_time.append(get_start_time(time, waste_time))
        e_time.append(get_time(time))

    for i in range(len(s)):
        now_e_time = e_time[i]
        cnt = 0

        # 끝난시간을 기준으로 이전에 시작시간들은 같은 트랜잭션안에 포함되므로 처리량에 +1 한다.
        # i번째 끝난시간은 시작시간도 i번째 이므로 j를 i부터 시작시킨다.
        for j in range(i, len(s)):
            # 1ms 빼준다.
            if now_e_time > s_time[j] - 1000:
                cnt += 1
        answer = max(cnt, answer)

    return answer


print(solution(s))
