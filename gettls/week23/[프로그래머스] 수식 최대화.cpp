#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<char> s;
vector<string> list;
vector<char> op_list;
long long solution(string expression) {
    long long answer = 0;
    long long m = 0;
    for (int i = 0; i < expression.size(); i++) {
        string str = "";
        if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
            s.insert(expression[i]);
            str += expression[i];
        }
        else {
            while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9') {
                str += expression[i];
                i++;
            }
            i--;
        }
        list.push_back(str);
    }
    for (auto t : s) op_list.push_back(t);

    do {
        char op;
        vector<string> str = list;
        for (int i = 0; i < op_list.size(); i++) {
            op = op_list[i];

            for (int j = 0; j < str.size(); j++) {
                if (str[j][0] != op || str[j].size() > 1) continue;
                string a = str[j - 1], b = str[j + 1];
                int k = j;
                int asize = a.size(), bsize = b.size();
                long long res;
                if (op == '*') res = stoll(a) * stoll(b);
                else if (op == '+') res = stoll(a) + stoll(b);
                else if (op == '-') res = stoll(a) - stoll(b);

                str[j] = to_string(res);
                str.erase(str.begin() + j + 1);
                str.erase(str.begin() + j - 1);
                j = 0;
            }
        }
        answer = max(answer, abs(stoll(str.front())));
    } while (next_permutation(op_list.begin(), op_list.end()));

    return answer;
}

int main() {
    solution("100-200*300-500+20");
}