#include <string>
#include <vector>
#include <iostream>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
int n, l;
int arr[100][100];
int v[100];

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return false;
	else return true;
}

//경사로 설치 가능 여부
bool installabe(int x, int y, int dir) { 
	// dir = 0 : 세로 축, dir = 1 : 가로 축

	if (dir) { // 가로 축 확인
		if (arr[x][y] == arr[x][y + 1] + 1) { // 내리막
			for (int i = 1; i <= l; i++) {
				if (v[y + i]) return false;
				if (!isRange(x, y + i)) return false;
				if (arr[x][y + i] != arr[x][y + 1]) return false;
			}

			for (int i = 1; i <= l; i++) v[y + i] = 1;
		}
		else if (arr[x][y] + 1 == arr[x][y + 1]) { // 오르막
			for (int i = 0; i < l; i++) {
				if (v[y - i]) return false;
				if (!isRange(x, y - i)) return false;
				if (arr[x][y - i] != arr[x][y]) return false;
			}
			for (int i = 0; i < l; i++) v[y - i] = 1;
		}
		else return false;
	}
	else { // 세로 축 확인
		if (arr[x][y] == arr[x + 1][y] + 1) { // 내리막
			for (int i = 1; i <= l; i++) {
				if (v[x + i]) return false;
				if (!isRange(x + i, y)) return false;
				if (arr[x + i][y] != arr[x + 1][y]) return false;
			}
			for (int i = 1; i <= l; i++) v[x + i] = 1;
		}
		else if (arr[x][y] + 1 == arr[x + 1][y]) { // 오르막
			for (int i = 0; i < l; i++) {
				if (v[x - i]) return false;
				if (!isRange(x - i, y)) return false;
				if (arr[x - i][y] != arr[x][y]) return false;
			}
			for (int i = 0; i < l; i++) v[x - i] = 1;
		}
		else return false;
	}
	return true;
}


bool check(int x, int y, int dir) {

	fill(v, v + n, 0);

	if (dir) { // 가로 축 확인
		for (int y = 0; y < n; y++) {
			if (y == n - 1) return true;
			if (arr[x][y] != arr[x][y + 1]) {
				if (installabe(x, y, dir)) {
					if (arr[x][y] > arr[x][y + 1]) y += l-1; // 내리막길
				}
				else return false;
			}
		}
	}

	else { // 세로 축 확인
		for (int x = 0; x < n; x++) {
			if (x == n - 1) return true;
			if (arr[x][y] != arr[x + 1][y]) {
				if (installabe(x, y, dir)) {
					if (arr[x][y] > arr[x + 1][y]) x += l-1;
				}
				else return false;
			}
		}
	}
}


int main() {
	cin >> n >> l;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < n; i++) {
		if (check(0, i, 0)) cnt++;
		if (check(i, 0, 1)) cnt++;
	}

	cout << cnt;
}