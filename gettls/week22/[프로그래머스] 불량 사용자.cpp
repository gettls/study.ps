#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> s;
int v[8];
vector<string> ban, user;
vector<string> tmp;
void dfs(int idx) {
    if (idx == ban.size()) {
        string tmp;
        for (int i = 0; i < user.size(); i++) {
            if (v[i]) tmp += user[i];
        }
        s.insert(tmp);
        return;
    }

    for (int i = 0; i < user.size(); i++) {
        string u = user[i];
        string b = ban[idx];
        int flag = 1;
        if (v[i]) continue;
        if (u.size() != b.size()) continue;
        for (int j = 0; j < u.size(); j++) {
            if (b[j] == '*') continue;
            if (u[j] != b[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            v[i] = 1;
            dfs(idx + 1);
            v[i] = 0;
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user = user_id;
    ban = banned_id;
    dfs(0);
    answer = s.size();
    return answer;
}