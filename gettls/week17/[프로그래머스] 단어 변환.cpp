#include <string>
#include <vector>

using namespace std;

int v[51], ans = 2e9;

bool canChange(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt == 1) return true;
    else return false;
}

void dfs(vector<string> words, string cur, string target, int cnt) {
    if (cur == target) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (canChange(cur, words[i]) && !v[i]) {
            v[i] = 1;
            dfs(words, words[i], target, cnt + 1);
            v[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    dfs(words, begin, target, 0);

    return answer;
}

int main() {
    vector<string> v = { "hot", "dot", "dog", "lot", "log", "cog" };
    solution("hit", "dog", v);
}

/*
* begin :"hit"
* target : "cog"
* {"hot", "dot", "dog", "lot", "log", "cog"}
* "hit" -> "dot" -> "dog" -> "cog"
* 4
*/