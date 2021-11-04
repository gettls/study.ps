#include <string>
#include <vector>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int n;
int arr[50][50], d[50][50];
int dx[] = { 0,-1,0,1 }, dy[] = { 1,0,-1,0 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	d[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == 1 && d[nx][ny] > d[x][y]) { // Èò ¹æ
				d[nx][ny] = d[x][y];
				q.push({ nx,ny });
			}
			else if (arr[nx][ny] == 0 && d[nx][ny] > d[x][y] + 1) { // °ËÀº ¹æ
				d[nx][ny] = d[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
			d[i][j] = 987654321;
		}
	bfs();
	cout << d[n - 1][n - 1];
}