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
int n, m;
int arr[100][100];
int d[100][100];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };

void bfs() {
	queue <pair<int, int>> q;
	q.push({ 0,0 });
	d[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 1) {
				if (d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j]) d[i][j] = 1e9;
		}
	}
	bfs();
	cout << d[n - 1][m - 1];
}