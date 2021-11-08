
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 1001;
    int cnt;
    if (s.length() == 1) return 1;
    string result;
    for (int i = 1; i <= s.size() / 2; i++) {
        string str = s.substr(0, i);
        cnt = 1;
        for (int j = i; j < s.size(); j += i) {
            string cmp = s.substr(j, i);
            if (str == cmp) {
                cnt++;
            }
            else {
                if (cnt == 1) result.append(str);
                else {
                    result.append(to_string(cnt));
                    result.append(str);
                }
                str = cmp;
                cnt = 1;
            }
        }
        if (cnt != 1) result.append(to_string(cnt));
        result.append(str);

        if (answer > result.length()) answer = result.length();
        result.clear();
    }
    return answer;
}