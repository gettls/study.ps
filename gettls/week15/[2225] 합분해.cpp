#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

long long dp[201][201]; //[n][k]
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 200; i++) {
		dp[i][1] = 1;
		dp[1][i] = i;

		dp[i][0] = 0;
		dp[0][i] = 1;
	}

	// [n][k]를 만드는 경우의 수
	// [n][k-1] + [n-1][k-1] + [n-2][k-1] + .... + [0][k-1]
	// [n-1][k-1] + [n-2][k-1] + .... + [0][k-1] = [n-1][k]
	// [n][k] = [n][k-1] + [n-1][k]

	for (int i = 2; i <= 200; i++) {
		for (int j = 2; j <= 200; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	cout << dp[n][k];
}
