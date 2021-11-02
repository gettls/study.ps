#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int k, W, H, INF = 10000000;
int arr[200][200], v[200][200][31];

int jump_x[] = { -2,-1,1,2,-2,-1,1,2 }, jump_y[] = { -1,-2,-2,-1,1,2,2,1 };
int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= W || y >= H) return false;
	return true;
}

int bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ k,{ 0,0 } });
	v[0][0][k] = 0;
	while (!q.empty()) {
		int x = q.front().second.second;
		int y = q.front().second.first;
		int left = q.front().first;
		if (x == W - 1 && y == H - 1) return v[y][x][left];
		q.pop();
		if (left > 0) {
			for (int i = 0; i < 8; i++) {
				int nx = x + jump_x[i];
				int ny = y + jump_y[i];
				if (!isRange(nx, ny)) continue;
				if (arr[ny][nx] == 1) continue;
				if (v[ny][nx][left - 1] > v[y][x][left] + 1) {
					v[ny][nx][left - 1] = v[y][x][left] + 1;
					q.push({ left - 1, {ny,nx} });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isRange(nx, ny)) continue;
			if (arr[ny][nx] == 1) continue;
			if (v[ny][nx][left] > v[y][x][left] + 1) {
				v[ny][nx][left] = v[y][x][left] + 1;
				q.push({ left,{ny,nx} });
			}
		}
	}

	return -1;
}

int main() {
	cin >> k >> W >> H;



	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
			for (int a = 0; a <= k; a++) v[i][j][a] = INF;
		}
	}

	cout << bfs();
}