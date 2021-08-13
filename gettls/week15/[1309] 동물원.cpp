#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

// [0][] : X
// [1][] : ¿ÞÂÊ
// [2][] : ¿À¸¥ÂÊ
int dp[3][100001];

int main() {

	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;

	int n;
	cin >> n;


	for (int i = 2; i <= n; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % 9901;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 9901;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % 9901;
	}

	cout << (dp[0][n] + dp[1][n] + dp[2][n]) % 9901;
}
