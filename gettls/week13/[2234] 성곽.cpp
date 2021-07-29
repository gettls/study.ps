#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int n, m;
int dx[] = { 0,-1,0,1 }, dy[] = { -1,0,1,0 }; // ¼­ºÏµ¿³²
int wall[] = { 1,2,4,8 };
int flag[50][50];
int arr[50][50];
vector<int> flag_size;


int bfs(int a, int b, int f) {
	int tmp[50][50], v[50][50];
	memcpy(tmp, arr, sizeof(arr));
	memset(v, 0, sizeof(v));
	queue<pair<int, int>> q;
	q.push({ a,b });
	flag[a][b] = f;
	v[a][b] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		int usedWall[4] = { 0 };
		for (int i = 3; i >= 0; i--) {
			if (tmp[x][y] - wall[i] >= 0) {
				usedWall[i] = 1;
				tmp[x][y] -= wall[i];
			}
		}
		for (int i = 0; i < 4; i++) {
			if (usedWall[i] == 1) continue;
			int nx = x + dx[i], ny = y + dy[i];
			if (v[nx][ny] == 1) continue;
			v[nx][ny] = 1;
			flag[nx][ny] = f;
			q.push({ nx,ny });
			cnt++;
		}
	}
	// return flag's size
	return cnt;
}

int check(int a, int b, int f) {
	int v[50][50];
	memset(v, 0, sizeof(v));

	int ret = flag_size[f];
	queue<pair<int, int>> q;
	q.push({ a,b });
	v[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (v[nx][ny] == 1) continue;
			v[nx][ny] = 1;
			if (flag[nx][ny] != f) {
				ret = max(ret, flag_size[flag[nx][ny]] + flag_size[f]);
			}
			else {
				q.push({ nx,ny });
			}
		}

	}
	return ret;
}


int main() {
	int ans1 = 0, ans2 = 0, ans3 = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	flag_size.push_back(0); // for sync
	int f = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (flag[i][j] == 0) {
				int cnt = bfs(i, j, f++);
				if (cnt > ans2) ans2 = cnt;
				flag_size.push_back(cnt);
			}
		}
	}

	for (int f = 1; f <= flag_size.size(); f++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (flag[i][j] == f) {
					ans3 = max(check(i, j, f), ans3);
				}
			}
		}
	}

	ans1 = flag_size.size() - 1;
	printf("%d\n%d\n%d", ans1, ans2, ans3);

}