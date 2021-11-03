#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int W, H, INF = 987654321;
char arr[100][100];
int d[100][100][4], res = INF;
int dx[] = { 0,1 ,0,-1 }, dy[] = { 1,0,-1,0 };
queue<pair<int, int>> laser;

bool isRange(int x, int y) {
	if (x < 0 || x >= H || y < 0 || y >= W) return false;
	return true;
}

bool isWall(int x, int y) {
	if (arr[x][y] == '*') return true;
	return false;
}

void bfs(int a, int b) {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{ a,b } }); q.push({ 1,{ a,b } });
	q.push({ 2,{ a,b } }); q.push({ 3,{ a,b } });
	d[a][b][0] = d[a][b][1] = d[a][b][2] = d[a][b][3] = 0;
	while (!q.empty()) {
		int x = q.front().second.first, y = q.front().second.second;
		int dir = q.front().first;
		q.pop();
		if (x == laser.front().first && y == laser.front().second) {
			res = min(res, d[x][y][dir]);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!isRange(nx, ny) || isWall(nx, ny)) continue;

			if (i == dir && d[nx][ny][i] > d[x][y][dir]) {
				d[nx][ny][i] = d[x][y][dir];
				q.push({ i,{nx,ny} });
			}

			else if (i != dir && d[nx][ny][i] > d[x][y][dir] + 1) {
				d[nx][ny][i] = d[x][y][dir] + 1;
				q.push({ i,{nx,ny} });
			}
		}
	}
}

int main() {
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char c;
			cin >> c;
			arr[i][j] = c;
			if (c == 'C') {
				laser.push({ i,j });
			}
			for (int k = 0; k < 4; k++) d[i][j][k] = INF;
		}
	}

	int x = laser.front().first, y = laser.front().second;
	laser.pop();
	bfs(x, y);
	cout << res;
}