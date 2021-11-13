def solution(s):
    max_len = int(1e9)

    if len(s) == 1:
        return 1

    for r in range(1, len(s) // 2 + 1):
        cut = s[:r]
        cnt = 1
        result = ""
        for i in range(r, len(s), r):
            if s[i:i+r] == cut:
                cnt += 1

            else:
                if cnt == 1:
                    result += cut
                    cut = s[i:i + r]
                else:
                    result += str(cnt) + cut
                    cut = s[i:i+r]
                cnt = 1

        if cnt == 1:
            result += cut
        else:
            result += str(cnt) + cut

        if len(result) < max_len:
            max_len = min(len(result), max_len)

    return max_len

print(solution('a'))
