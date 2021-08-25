#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> div;
    int sum = brown + yellow;
    for (int i = 1; i <= sum; i++) if (sum % i == 0) div.push_back(i);

    for (int i = 0; i < div.size(); i++) {
        int x = div[i];
        int y = div[div.size() - 1 - i];

        if (x >= y && y >= 3 && x >= 3) {
            if ((x - 2) * (y - 2) == yellow) {
                answer.push_back(x);
                answer.push_back(y);
            }
        }
    }


    return answer;
}