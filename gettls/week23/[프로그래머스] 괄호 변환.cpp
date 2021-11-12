#include <string>
#include <vector>
#include <stack>
using namespace std;
// 균형잡힌 괄호 문자열, 올바른 괄호 문자열
// 1. 빈 문열자 -> 빈 문자열 반환
// 2. w => u(더 이상 분리 불가), v(빈 문자열 가능) 분리 (균형잡힌 괄호 문자열)

// 3. u (올바른 문자열) -> v를 1번으로
// 3-1. u 에 결과를 갖다 붙힘

// 4. u (올바른 문자열 X)
// 4.1. 빈 문자열에 '(' 넣음
// 4.2 v 를 1 번으로 돌리고 결과를 '('에 갖다 붙힘
// 4.3 ')' 넣음
// 4.4 u 의 처음, 마지막 문자 제거하고 나머지 방향 바꿔서 뒤에 붙임
// 4.5 반환
string answer = "";
string w;
bool isBalanced(string str) { // 균형잡힌 문자열
    stack<char> a, b;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') a.push(str[i]);
        else b.push(str[i]);
    }
    if (a.size() == b.size()) return true;
    return false;
}

bool isCorrect(string str) { // 올바른 문자열
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') s.push(str[i]);
        else {
            if (s.empty()) return false;
            s.pop();
        }
    }
    if (!s.empty()) return false;
    return true;
}

string convert(string str) {
    str.erase(0, 1);
    str.erase(str.end() - 1, str.end());
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') str[i] = ')';
        else str[i] = '(';
    }
    return str;
}

string go(string u) {
    if (u == "") return u;
    else {
        string a, b;
        for (int i = 0; i < u.size(); i++) {
            a = u.substr(0, i + 1);
            if (i + 1 < u.size())b = u.substr(i + 1);
            else b = "";
            if (isCorrect(a)) {
                return a += go(b);
            }
            else if (isBalanced(a)) {
                string tmp = "(";
                tmp += go(b) + ")";
                tmp += convert(a);
                return  a = tmp;
            }
        }
    }
}


string solution(string p) {
    w = p;
    answer = go(p);
    return answer;
}


int main() {
    solution("()))((()");
}