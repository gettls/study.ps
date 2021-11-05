#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i].substr(0, 1);
        string num = operations[i].substr(2);
        if (op == "I") {
            dq.push_back(stoi(num));
        }
        else if (!dq.empty() && op == "D") {
            sort(dq.begin(), dq.end()); // ascending order

            if (num == "-1") { // erase min
                dq.pop_front();
            }
            else if (num == "1") { // erase max
                dq.pop_back();
            }
        }
    }
    sort(dq.begin(), dq.end());
    if (dq.empty()) {
        answer.push_back(0); answer.push_back(0);
    }

    else {
        answer.push_back(dq.front()); answer.push_back(dq.back());
    }

    return answer;
}
