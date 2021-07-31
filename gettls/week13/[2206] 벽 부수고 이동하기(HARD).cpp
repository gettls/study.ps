#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int n, m;
int arr[1000][1000], v[1000][1000][2];
// v[][][부순 벽 개수 == 0] : 부시기 전
// v[][][부순 벽 개수 == 1] : 부신 후
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };

int bfs(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { a,b },0 });
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second;
		int cnt = q.front().second;
		if (x == n - 1 && y == m - 1) {
			return v[x][y][cnt];
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 벽이고 아직 벽을 뚫지 않은 경우
			if (arr[nx][ny] == 1 && cnt == 0) {
				v[nx][ny][cnt + 1] = v[x][y][cnt] + 1;
				q.push({ {nx,ny}, cnt + 1 });
			}
			// 길이고 아직 방문하지 않은 경우
			if (arr[nx][ny] == 0 && v[nx][ny][cnt] == 0) {
				v[nx][ny][cnt] = v[x][y][cnt] + 1;
				q.push({ {nx,ny},cnt });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	v[0][0][0] = 1; 
	cout<<bfs(0, 0);
	
}