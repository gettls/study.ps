#include <string>
#include <vector>

using namespace std;
int ans = 0;
void dfs(vector<int> numbers, int cnt, int idx, int sum, int target) {
    if (numbers.size() == cnt) {
        if (sum == target) ans++;
        return;
    }
    dfs(numbers, cnt + 1, idx + 1, sum + numbers[idx], target);
    dfs(numbers, cnt + 1, idx + 1, sum - numbers[idx], target);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, 0, 0, target);
    answer = ans;
    return answer;
}