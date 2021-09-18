#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#pragma warning (disable:4996)
using namespace std;

int arr[100][100], v[100][100];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int n, m;

void labeling() {
	for (int i = 0; i < n; i++) fill(v[i], v[i] + m, 0);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	arr[0][0] = -1;
	v[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] != 1 && !v[nx][ny]) {
				q.push({ nx,ny });
				arr[nx][ny] = -1;
				v[nx][ny] = 1;
			}
		}
	}
}

void corruption() {
	int tmp[100][100];
	memcpy(tmp, arr, sizeof(arr));
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (arr[x][y] == 1 && arr[nx][ny] == -1) {
					tmp[x][y] = 0;
					break;
				}
			}
		}
	}
	memcpy(arr, tmp, sizeof(tmp));
}

int calc() {
	int sum = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (arr[x][y] == 1) sum++;
		}
	}
	return sum;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int t = 0, left = 0, cnt = 0;
	while (t = calc()) {
		labeling();
		corruption();
		left = t;
		cnt++;
	}

	printf("%d\n%d", cnt, left);
}