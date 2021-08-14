#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int arr[1001][1001], dp[1001][1001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int res = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j]) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				if (dp[i][j] > res) res = dp[i][j];
			}
		}
	}

	cout << res * res;
}
