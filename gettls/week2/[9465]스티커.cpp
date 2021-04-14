#include<iostream>
#pragma warning (disable:4996)
using namespace std;
int arr[2][100001], dp[2][100001];
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
        //dp[0][n] : arr[0][n]까지 떼어냈을 때 최대 값 (arr[0][n] 포함)
        //dp[1][n] : arr[1][n]까지 떼어냈을 때 최대 값 (arr[1][n] 포함)
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1], dp[1][1] = arr[1][1];
           
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}		
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}