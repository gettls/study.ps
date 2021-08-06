#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

char a[100][100], b[100][100];
int va[100][100], vb[100][100];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
int n;

int bfs(int a, int b, char map[100][100], int v[100][100]) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	v[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == map[x][y] && !v[nx][ny]) {
				v[nx][ny] = v[x][y];
				q.push({ nx,ny });
			}
		}
	}
	return 1;
}


int main() {
	cin >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'G') b[i][j] = 'R';
			else b[i][j] = a[i][j];
		}

	int ac = 0, bc = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!va[i][j]) ac += bfs(i, j, a, va);
			if (!vb[i][j]) bc += bfs(i, j, b, vb);
		}
	}

	printf("%d %d", ac, bc);
}