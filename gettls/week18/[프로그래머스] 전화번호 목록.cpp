#include <string>
#include <vector>
#include <set>
using namespace std;
set<string> s;
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (int i = 0; i < phone_book.size(); i++) {
        s.insert(phone_book[i]);
    }

    for (int i = 0; i < phone_book.size(); i++) {
        string cur = phone_book[i];
        for (int j = 1; j < cur.size(); j++) {
            string tmp = cur.substr(0, j);
            // 해당 접두어가 있다면
            if (s.find(tmp) != s.end()) return false;
        }
    }


    return answer;
}