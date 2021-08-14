#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

<<<<<<< HEAD
int dp[101][100001];
int main() {
	int n, k; // 개수, 무게

	cin >> n >> k;

	vector<pair<int, int>> list(n + 1);
	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		list[i] = { w,v }; // 무게, 가치
	}

	// dp[i][j] : i 번째 보석까지 사용해서 j 무게 배낭에 넣었을 때 최댓값

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			// 넣을 보석이 없거나, 배낭 무게가 0인 경우는 최댓값은 0
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				// i 번째 보석의 무게가 j 보다 큰 경우
				if (list[i].first > j) {
					dp[i][j] = dp[i - 1][j];
				}
				// i 번째 보석을 넣어서 j 무게 배낭에 넣었을 경우와
				// i 번째 보석을 넣지 않고 j 무게 배낭에 넣었을 경우를 비교
				else {
					dp[i][j] = max(dp[i - 1][j], list[i].second + dp[i - 1][j - list[i].first]);
				}
			}
		}
	}
	cout << dp[n][k];
=======
int dp[1001];
int n;

int main() {
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];
>>>>>>> 3270509c5e814e25ec0d7fbaa5a9e2446175bc90
}
