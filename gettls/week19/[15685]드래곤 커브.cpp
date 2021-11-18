#include <vector>
#include <iostream>
using namespace std;

// 동 북 서 남
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int n, arr[101][101];
int x, y, d, g;
void go() {
	vector<int> v;
	v.push_back(d);
	for (int i = 0; i < g; i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			v.push_back((v[j] + 1) % 4);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int nx = x + dx[v[i]], ny = y + dy[v[i]];
		arr[nx][ny] = 1;
		x = nx, y = ny;
	}
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		// 좌표, 시작 방향, 세대
		cin >> y >> x >> d >> g;
		arr[x][y] = 1;
		go();
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] && arr[i][j + 1] &&
				arr[i + 1][j] && arr[i + 1][j + 1]) cnt++;
		}
	}
	cout << cnt;
}
[출처] [15685] 드래곤 커브 | 작성자 gettls