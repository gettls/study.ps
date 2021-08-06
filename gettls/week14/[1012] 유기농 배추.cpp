#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning (disable:4996)

int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
int arr[50][50], v[50][50];
int t;
int m, n, k;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	v[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 1 && !v[nx][ny]) {
				v[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		memset(arr, 0, sizeof(arr));
		memset(v, 0, sizeof(v));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !v[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}

		cout << cnt << "\n";
	}

}