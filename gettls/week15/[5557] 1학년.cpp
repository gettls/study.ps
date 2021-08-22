#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

long long dp[100][21]; // i 번째 숫자에서 정수 j 가 나올 수 있는 경우의 수
vector<int> v;
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	// v[n-1] 은 결과값
	dp[0][v[0]] = 1;
	for (int i = 1; i < v.size() - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0 && j + v[i] >= 0 && j + v[i] <= 20) {
				dp[i][j + v[i]] += dp[i - 1][j];
			}
			if (dp[i - 1][j] != 0 && j - v[i] >= 0 && j - v[i] <= 20) {
				dp[i][j - v[i]] += dp[i - 1][j];
			}

		}
	}

	cout << dp[n - 2][v[n - 1]];
}
