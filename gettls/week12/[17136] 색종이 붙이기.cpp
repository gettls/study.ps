#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n, ans = 2e9;
int arr[10][10],paper[5];

void cover(int x, int y, int size, int update) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			arr[i][j] = update;
		}
	}
}

bool check(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] == 0) return false;
		}
	}
	return true;
}


void dfs(int cnt) {
	int x, y, c = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j]) {
				x = i, y = j;
				c = 1;
				break;
			}
		}
		if (c) break;
	}

	if (!c) {
		if (ans > cnt) ans = cnt;
		return;
	}

	for (int i = 0; i < 5; i++){
        // 색종이 다 쓰거나
		if (paper[i] == 0) continue;
        // 색종이 크기가 범위를 넘으면 pass
		if (x + (5 - i) >= 10 || y + (5 - i) >= 10) continue;
		if (check(x, y, 5 - i)) {
			cover(x, y, 5 - i, 0);
			paper[i]--;
			dfs(cnt + 1);
			paper[i]++;
			cover(x, y, 5 - i, 1);
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	fill(paper, paper + 5, 5);
	dfs(0);
	if (ans == 2e9) ans = -1;
	cout << ans;
}     