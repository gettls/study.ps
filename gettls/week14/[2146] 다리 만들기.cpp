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
int n;
int arr[100][100], d[100][100];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };

void labeling(int a, int b, int flag) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	arr[a][b] = flag;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = flag;
				q.push({ nx,ny });
			}
		}
	}
}

int bfs(int a, int b, int flag) {
	int ret = 1e9;
	for (int i = 0; i < n; i++) fill(d[i], d[i] + n, 1e9);
	queue<pair<int, int>> q;
	q.push({ a,b });
	d[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == 0) {
				if (d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else if (arr[nx][ny] != flag && arr[nx][ny] != 0) {
				ret = min(ret, d[x][y]);
			}
		}
	}
	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int flag = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 1) labeling(i, j, flag--);


	int ans = 1e9;

	for (int x = -1; x >= flag; x--) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == x) {
					ans = min(ans, bfs(i, j, x));
				}
			}
	}
	cout << ans;
}