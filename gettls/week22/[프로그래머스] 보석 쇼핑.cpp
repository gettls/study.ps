#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    // counting kind of gems
    set<string> kind;
    for (int i = 0; i < gems.size(); i++) kind.insert(gems[i]);
    map<string, int> m;
    pair<int, int> pos;
    deque<string> dq;

    int start = 0, startP = 0, length = 0;
    for (int i = 0; i < gems.size(); i++) {
        m[gems[i]]++;
        dq.push_back(gems[i]);

        while (1) {
            int flag = 0;
            if (m[dq.front()] > 1) {
                m[dq.front()]--;
                dq.pop_front();
                startP++;
            }
            else {
                break;
            }
        }
        if (m.size() == kind.size() && kind.size() >= dq.size()) {
            start = startP;
            length = dq.size();
        }

    }

    return answer;
}

int main() {
    solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
}
