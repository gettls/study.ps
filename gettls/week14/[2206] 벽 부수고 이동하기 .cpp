#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int arr[1000][1000], d[1000][1000][2];
int n, m;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };


int bfs() {
	queue<pair<pair<int, int>, int>> q; // {x,y}, block
	q.push({ { 0,0 }, 0 });
	d[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second;
		int wall = q.front().second;
		if (x == n - 1 && y == m - 1) return d[x][y][wall];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 길이고 아직 방문하지 않은 경우
			if (!d[nx][ny][wall] && !arr[nx][ny]) {
				d[nx][ny][wall] = d[x][y][wall] + 1;
				q.push({ {nx,ny}, wall });
			}
			// 벽이고 아직 부수지 않은 경우 
			if (!wall && arr[nx][ny]) {
				d[nx][ny][wall + 1] = d[x][y][wall] + 1;
				q.push({ {nx,ny}, wall + 1 });
			}
		}
	}
	return -1;
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}

	cout << bfs();

}
