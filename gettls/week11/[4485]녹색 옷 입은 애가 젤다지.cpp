#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int INF = 2e9;
int arr[125][125], d[125][125];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int n;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (d[x][y] + arr[nx][ny] < d[nx][ny]) {
				q.push({ nx,ny });
				d[nx][ny] = d[x][y] + arr[nx][ny];
			}
		}
	}
}


int main() {
	int cnt = 0;
	while (1) {
		cnt++;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				d[i][j] = INF;
			}
		}
		d[0][0] = arr[0][0];
		bfs(0, 0);
		printf("Problem %d: %d\n", cnt, d[n - 1][n - 1]);
	}
 }