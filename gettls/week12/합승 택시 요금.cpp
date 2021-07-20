#include <string>
#include <vector>
typedef long long ll;
using namespace std;
ll INF = 2e9;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    ll d[200][200];

    for (int i = 0; i < n; i++) fill(d[i], d[i] + n, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i == j) d[i][j] = 0;
    }

    for (int i = 0; i < fares.size(); i++) {
        int C = fares[i][0], D = fares[i][1], F = fares[i][2];
        d[C - 1][D - 1] = F;
        d[D - 1][C - 1] = F;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int min = d[s - 1][a - 1] + d[s - 1][b - 1];
    answer = s - 1;
    for (int i = 0; i < n; i++) {
        if (d[s - 1][i] + d[i][a - 1] + d[i][b - 1] <= min) {
            min = d[s - 1][i] + d[i][a - 1] + d[i][b - 1];
            answer = min;
        }
    }
    return answer;
}
