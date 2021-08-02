#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int n, m;
int arr[500][500];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
int dp[500][500];
int cnt;
int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (arr[x][y] > arr[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}
int main() { 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	dfs(0, 0);
	cout << dp[0][0];
}  