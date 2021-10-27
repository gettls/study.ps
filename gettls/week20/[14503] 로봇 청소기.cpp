#include <string>
#include <vector>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int r, c, d;
int N, M, arr[50][50];
// 바라보고 있는 방향
// d => 북, 동, 남, 서
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int v[50][50];

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	return true;
}


bool check(int x, int y) {
	// 청소하지 않은 곳, 벽이 아닌곳, 범위를 넘지 않는 곳
	if (v[x][y] != 1 && arr[x][y] == 0 && isRange(x, y)) return true;
	return false;
}

void cleaning() {
	queue<pair<int, int>> q;
	q.push({ r,c });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int flag = 1;
		v[x][y] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (check(nx, ny)) {
				q.push({ nx,ny });
				flag = 0;
				break;
			}
		}

		if (flag) { // 4면 중 갈 곳이 없는 경우 => 후진
			int nx = x - dx[d];
			int ny = y - dy[d];
			if (arr[nx][ny] == 1) 
				break;
			else q.push({ nx,ny });
		}
	}

}
int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cleaning();
	int cnt = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (v[i][j]) cnt++;
	cout << cnt;
}