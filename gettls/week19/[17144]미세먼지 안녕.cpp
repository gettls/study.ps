#include <string>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
int arr[50][50];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int r, c, t;
pair<int, int> up, down;

void spread() {
	int tmp[50][50];
	for (int i = 0; i < r; i++) fill(tmp[i], tmp[i] + c, 0);
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			int dust = arr[x][y];
			if (arr[x][y] > 0) {
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (arr[nx][ny] == -1) continue;
					tmp[nx][ny] += arr[x][y] / 5;
					dust -= arr[x][y] / 5;
				}
			}
			arr[x][y] = dust;
		}
	}
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			arr[x][y] += tmp[x][y];
		}
	}
}

void vacumm() {
	// up
	int x = up.first, y = up.second;
	while (x > 0) {
		if (arr[x][y] != -1) arr[x][y] = arr[x - 1][y];
		x--;
	}
	while (y < c - 1) {
		arr[x][y] = arr[x][y + 1];
		y++;
	}
	while (x < up.first) {
		arr[x][y] = arr[x + 1][y];
		x++;
	}
	while (y > 0) {
		if (arr[x][y - 1] == -1) arr[x][y] = 0;
		else arr[x][y] = arr[x][y - 1];
		y--;
	}
	// down
	x = down.first, y = down.second;
	while (x < r - 1) {
		if (arr[x][y] != -1) arr[x][y] = arr[x + 1][y];
		x++;
	}
	while (y < c - 1) {
		arr[x][y] = arr[x][y + 1];
		y++;
	}
	while (x > down.first) {
		arr[x][y] = arr[x - 1][y];
		x--;
	}
	while (y > 0) {
		if (arr[x][y - 1] == -1) arr[x][y] = 0;
		else arr[x][y] = arr[x][y - 1];
		y--;
	}
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int flag = 0;
	for (int i = 0; i < r; i++) {
		if (arr[i][0] == -1 && !flag) {
			flag = 1;
			up = { i,0 };
		}
		if (arr[i][0] == -1 && flag) down = { i,0 };
	}
	while (t--) {
		spread();
		vacumm();
	}

	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] > 0) sum += arr[i][j];
		}
	}
	cout << sum;
}