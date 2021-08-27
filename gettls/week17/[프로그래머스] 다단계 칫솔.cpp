#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    map<string, pair<string, int>> m; // child, (parent, profit)

    for (int i = 0; i < enroll.size(); i++) {

        m[enroll[i]].first = referral[i];
        m[enroll[i]].second = 0;
    }

    for (int i = 0; i < amount.size(); i++) {
        string mem = seller[i];
        int p = amount[i] * 100;
        while (1) {
            m[mem].second += (p - p / 10);
            p = p / 10;
            if (m[mem].first == "-") break;
            mem = m[mem].first;
        }
    }

    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(m[enroll[i]].second);
    }


    return answer;
}


int main() {
    vector<string> e = { "john", "mary", "edward",
        "sam", "emily", "jaimie", "tod", "young" };
    vector<string> r = { "-", "-", "mary", "edward", "mary",
        "mary", "jaimie", "edward" };
    vector<string> s = { "young", "john", "tod",
        "emily", "mary"
    };
    vector<int> m = { 12,4,2,5,10 };
    solution(e, r, s, m);
}