#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 1;
    int m = 0;

    for (int i = 0; i < stones.size(); i++) m = max(m, stones[i]);

    int l = 1, r = m;

    while (l <= r) {
        int mid = (l + r) / 2; // number of friends
        int cnt = 0, tmp = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] < mid) {
                tmp++;
            }
            else {
                tmp = 0;
            }
            cnt = max(cnt, tmp);
        }

        if (cnt < k) {
            answer = mid;
            l = mid + 1;
        }

        else r = mid - 1;
    }

    return answer;
}
