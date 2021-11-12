#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> c;
vector<string> order;
vector<string> list;
vector<string> answer;
void go(int idx, int cnt, int size, string tmp) {
    if (cnt == size) {
        string str;
        for (int i = 0; i < c.size(); i++) {
            if (c[i]) str += tmp[i];
        }
        sort(str.begin(), str.end());
        list.push_back(str);
        return;
    }

    for (int i = idx; i < tmp.size(); i++) {
        if (c[i] == 0) {
            c[i] = 1;
            go(i + 1, cnt + 1, size, tmp);
            c[i] = 0;
        }
    }
}

void makeResult() {
    vector<string> v;
    string tmp = list[0];
    int max = -1, cnt = 0;
    for (int i = 0; i < list.size(); i++) {
        if (tmp == list[i]) cnt++;
        else {
            if (cnt > max) {
                max = cnt;
                v.clear();
                v.push_back(tmp);
            }
            else if (cnt == max) {
                v.push_back(tmp);
            }
            cnt = 1;
            tmp = list[i];
        }
    }

    if (cnt > max) {
        max = cnt;
        v.clear();
        v.push_back(tmp);
    }
    else if (cnt == max) {
        v.push_back(tmp);
    }

    if (max < 2) return;
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    order = orders;

    for (int i = 0; i < course.size(); i++) {
        list.clear();
        for (int j = 0; j < order.size(); j++) {
            if (order[j].size() < course[i]) continue;
            c.resize(order[j].size(), 0);
            go(0, 0, course[i], order[j]);
        }
        sort(list.begin(), list.end());
        makeResult();
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    solution({ "ABCD", "ABCD", "ABCD" },
        { 2,3,4 });
}