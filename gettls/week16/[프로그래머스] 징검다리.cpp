#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    int s = 0, e = distance;
    while (s <= e) {
        int mid = (s + e) / 2;
        int cnt = 0, pos = 0;
        for (int i = 0; i < rocks.size(); i++) {
            if (mid > rocks[i] - pos) cnt++;
            else {
                pos = rocks[i];
            }
        }
        if (cnt > n) {
            e = mid - 1;
        }
        else {
            answer = mid;
            s = mid + 1;
        }
    }
    return answer;
}
