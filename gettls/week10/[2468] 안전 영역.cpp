#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;

int n, cnt = 1, m_height;
int arr[100][100], v[100][100];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void find(int a, int b, int h) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	v[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] <= h || v[nx][ny]) continue;
			q.push({ nx, ny });
			v[nx][ny] = 1;
		}
	}
}

int main() {
	m_height = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			m_height = max(m_height, arr[i][j]);
		}
	}
	
	int res = 0;
	for (int l = 0; l <= m_height; l++) {
		for (int i = 0; i < n; i++) fill(v[i], v[i] + n, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 0 && arr[i][j] > l) {
					find(i, j, l);
					cnt++;
				}
			}
		}
		res = max(res, cnt);
	}
	cout << res;
}

/*
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7
*/