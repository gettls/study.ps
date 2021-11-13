def solution(info, query):
    answer = []
    for q in query:
        q_s = q.split()
        cnt = 0
        for i in info:
            i_s = i.split()
            if q_s[0] != '-':
                if q_s[0] != i_s[0]:
                    continue
            if q_s[2] != '-':
                if q_s[2] != i_s[1]:
                    continue
            if q_s[4] != '-':
                if q_s[4] != i_s[2]:
                    continue
            if q_s[6] != '-':
                if q_s[6] != i_s[3]:
                    continue
            if int(q_s[7]) <= int(i_s[4]):
                cnt += 1
        answer.append(cnt)

    return answer

info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]

result = []





# ['java', 'backend', 'junior', 'pizza', '150']
# ['python', 'frontend', 'senior', 'chicken', '210']
# ['python', 'frontend', 'senior', 'chicken', '150']
# ['cpp', 'backend', 'senior', 'pizza', '260']
# ['java', 'backend', 'junior', 'chicken', '80']
# ['python', 'backend', 'senior', 'chicken', '50']
#
# ['java', 'backend', 'junior', 'pizza', '100']
# ['python', 'frontend', 'senior', 'chicken', '200']
# ['cpp', '-', 'senior', 'pizza', '250']
# ['-', 'backend', 'senior', '-', '150']
# ['-', '-', '-', 'chicken', '100']
# ['-', '-', '-', '-', '150']