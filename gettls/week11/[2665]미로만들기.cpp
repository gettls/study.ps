#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma warning(disable:4996)
int arr[50][50], d[50][50], v[50][50];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, INF = 2e9;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny]) {
				if (d[x][y] < d[nx][ny]) {
					d[nx][ny] = d[x][y];
					q.push({ nx,ny });
				}
			}
			else if (!arr[nx][ny]) {
				if (d[x][y] + 1 < d[nx][ny]) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}

	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
			// 해당 문제는 검은방의 개수를 저장하는
			// 배열 d를 INF로 초기화하는게 <<포인트>>
			// 최소값을 구하는 문제이기 때문에
			// 출발점에서 도착점까지 움직이며 최소값을 갱신해야 한다.
			d[i][j] = INF;
		}
	}
	d[0][0] = 0;
	bfs(0, 0);
	cout << d[n - 1][n - 1];
}