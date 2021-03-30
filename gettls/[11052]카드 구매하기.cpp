#include<iostream>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[1001];
	int dp[1001];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
    // dp[n] : n 개의 카드를 구매했을 때 최댓값
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i],dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];
}