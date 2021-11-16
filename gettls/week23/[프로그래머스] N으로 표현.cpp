#include <string>
#include <vector>

using namespace std;

int n, num;
int answer = 9;

void dfs(int cnt, int sum) {
    if (cnt > 8) return;

    if (sum == num) {
        answer = min(answer, cnt);
    }

    int tmp = 0;
    for (int i = 1; i + cnt <= 9; i++) {
        tmp = 10 * tmp + n;
        dfs(cnt + i, sum + tmp);
        dfs(cnt + i, sum - tmp);
        dfs(cnt + i, sum * tmp);
        dfs(cnt + i, sum / tmp);
    }
}


int solution(int N, int number) {
    n = N; num = number;
    dfs(0, 0);
    if (answer > 8) answer = -1;
    return answer;
}