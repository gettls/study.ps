#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9
#pragma warning (disable:4996)
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int n, m;
int arr[100][100],d[100][100];

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		fill(d[i], d[i] + m, INF);
	}

	priority_queue<pair<int, pair<int, int>>> pq; // (비용, (x,y))
	pq.push({ 0,{0,0} });
	d[0][0] = 0;

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[x][y] < dist) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int nextDist = dist + arr[nx][ny];
			if (d[nx][ny] > nextDist) {
				d[nx][ny] = nextDist;
				pq.push({ -nextDist,{nx,ny} });
			}
		}
	}

	cout << d[n - 1][m - 1];
}