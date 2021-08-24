#include <string>
#include <vector>
#include <map>
using namespace std;

string toupper(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 'a' + 'A';
    }
    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = toupper(str1);
    str2 = toupper(str2);
    vector<string> s1_list, s2_list;
    map<string, int> s1, s2;
    for (int i = 0; i < str1.size() - 1; i++) {
        if (!(str1[i] >= 'A' && str1[i] <= 'Z')
            || !(str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')) continue;
        string tmp = str1.substr(i, 2);
        s1_list.push_back(tmp);
        s1[tmp]++;
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (!(str2[i] >= 'A' && str2[i] <= 'Z')
            || !(str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')) continue;
        string tmp = str2.substr(i, 2);
        s2_list.push_back(tmp);
        s2[tmp]++;
    }

    int u = 0, n = 0;
    for (int i = 0; i < s1_list.size(); i++) {
        string str = s1_list[i];
        if (s2[str] == 0 && s1[str]) { // str1에는 있고 str2에는 없다면
            u++;
        }
        else if (s2[str] > 0) { // str2에 있다면 
            u += max(s1[str], s2[str]); // u 는 더 많은거
            n += min(s1[str], s2[str]); // n 은 더 적은거
            s1.erase(str); s2.erase(str); // 같은거 다 삭제
        }
    }
    for (int i = 0; i < s2_list.size(); i++) {
        string str = s2_list[i];
        if (s1[str] == 0 && s2[str]) { // str2 에는 있고 str1에는 없는것
            u++;
        }
    }
    if (u == 0) answer = 65536;
    else answer = (double)n / u * 65536;

    return answer;
}