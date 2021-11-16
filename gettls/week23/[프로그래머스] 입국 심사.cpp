#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    long long l = times.front(), r = times.back() * n;

    while (l <= r) {
        long long mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            if (mid / times[i] == 0) continue;
            cnt += (mid / times[i]);
        }

        if (cnt >= n) {
            answer = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }


    return answer;
}

int main() {
    solution(6, { 7,10 });
}