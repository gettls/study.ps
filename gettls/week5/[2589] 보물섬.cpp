#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
	
int n, m;
char arr[50][50];
int d[50][50], dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int dist[50][50];

void bfs(int a, int b) {
	int max = 0;
	memset(d, 0, sizeof(d));
	queue<pair<int, int>> q;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] != 'L' || d[nx][ny] != 0 || (nx == a && ny == b)) continue;
			q.push({ nx,ny });
			d[nx][ny] = d[x][y] + 1;
			if (d[nx][ny] > max) max = d[nx][ny];
		}
	}
	dist[a][b] = max;
}


int main() {
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1c", &arr[i][j]);
		}
		getchar();
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]=='L') {
				bfs(i, j);
				if (dist[i][j]  > res) res = dist[i][j];
			}
		}
	}
	cout << res;
}