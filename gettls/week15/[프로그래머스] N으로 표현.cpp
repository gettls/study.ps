#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[9];

bool isRanged(int x) {
    if (x >= 1 && x <= 32000) return true;
    return false;
}

int solution(int N, int number) {
    int answer = 0;
    bool c = false;
    int NN = 0, idx = 1;
    while (1) {
        NN = NN * 10 + N;
        if (NN > 32000) break;
        v[idx++].push_back(NN);
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= i / 2; j++) {
            for (int x = 0; x < v[j].size(); x++) {
                int a = v[j][x];
                for (int y = 0; y < v[i - j].size(); y++) {
                    int b = v[i - j][y];
                    if (isRanged(a + b)) v[i].push_back(a + b);
                    if (isRanged(a * b)) v[i].push_back(a * b);
                    if (isRanged(a / b)) v[i].push_back(a / b);
                    if (isRanged(b / a)) v[i].push_back(b / a);
                    if (isRanged(a - b)) v[i].push_back(a - b);
                    if (isRanged(b - a)) v[i].push_back(b - a);
                }
            }
        }

        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());

        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == number) {
                answer = i;
                return answer;
            }
        }
    }
    return -1;
}
