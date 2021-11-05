def solution(record):
    value = dict()
    value["test"] = "test"
    result = []
    answer = []
    for rec in record:
        cnt = 0
        start = 0
        status = 0
        for i in range(len(rec)):
            cut = i
            if rec[i] == " " and cnt == 0:
                cnt += 1
                if rec[start:cut] == "Enter":
                    status = 1
                elif rec[start:cut] == "Leave":
                    status = 2
                elif rec[start:cut] == "Change":
                    status = 3
                start = i + 1

            elif rec[i] == " " and cnt == 1:
                id_val = rec[start:cut]
                start = i + 1
                name = rec[start:]

                if status == 1:
                    value[id_val] = name
                    result.append((id_val, "Enter"))

                if status == 3:
                    value[id_val] = name

            elif i == len(rec) - 1:
                if status == 2:
                    id_val = rec[start:]
                    result.append((id_val, "Leave"))
                    del (value[id_val])

    for res in result:
        if res[1] == "Enter":
            answer.append(value.get(res[0]) + "님이 들어왔습니다.")
        if res[1] == "Leave":
            answer.append(value.get(res[0]) + "님이 나갔습니다.")

    return answer

print(solution(["Enter uid1234 Muzi","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))