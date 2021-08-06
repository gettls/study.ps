#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int r, c;
char arr[50][50];
int water[50][50], d[50][50];
vector<pair<int, int>> w_pos;
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };


void watering() {
	queue<pair<int, int>> q;
	for (int i = 0; i < w_pos.size(); i++){
		q.push({ w_pos[i].first, w_pos[i].second });
		water[w_pos[i].first][w_pos[i].second] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (water[nx][ny] != 1e9 || arr[nx][ny] == 'D'
				|| arr[nx][ny] == 'X') continue;
			water[nx][ny] = water[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}


void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	d[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			// 돌, 물 예정지역 못감
			if (arr[nx][ny] == 'X' || water[nx][ny] <= d[x][y] + 1) continue;
			if (d[nx][ny] != -1) continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx,ny });
		}
	}


}

int main() { 
	cin >> r >> c;
	int x, y;
	int tx, ty;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			water[i][j] = 1e9;
			d[i][j] = -1;
			if (arr[i][j] == '*') w_pos.push_back({ i,j });
			if (arr[i][j] == 'S') { x = i, y = j; }
			if (arr[i][j] == 'D') { tx = i, ty = j; }
		}
	watering();
	bfs(x, y); 
	if (d[tx][ty] == -1) cout << "KAKTUS";
	else cout << d[tx][ty];
}	