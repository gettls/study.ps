#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int size = progresses.size();
    vector<int> times(size, 0);

    for (int i = 0; i < size; i++) {
        times[i] = ceil((double)(100 - progresses[i]) / speeds[i]);
    }

    int cnt = 0, t = times[0];
    for (int i = 0; i < size; i++) {
        if (times[i] <= t) cnt++;
        else {
            answer.push_back(cnt);
            t = times[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);


    return answer;
}