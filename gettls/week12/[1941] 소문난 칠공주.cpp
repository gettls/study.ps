#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)

char arr[5][5];
int pick[25], ans;
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };

// 모든 경우를 확인하기 위해서는
// DFS/BFS 를 사용해서 풀 수 없다
// 모든 조합을 확인하기 위해 5x5 배열을 0~24까지의 인덱스로 표현했다.

// 근접한 경우
bool isAdj(int a, int b) {
	int cnt = 1;
	int v[5][5];
	memset(v, 0, sizeof(v));
	queue<pair<int, int>> q;
	q.push({ a,b });
	v[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (!v[nx][ny] && pick[nx * 5 + ny]) {
				q.push({ nx,ny });
				v[nx][ny] = 1;
				cnt++;
			}
		}
	}
	if (cnt == 7) return true;
	else return false;
}

// S의 개수가 4개 이상인지 확인
bool count() {
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (pick[i]) {
			int x = i / 5, y = i % 5;
			if (arr[x][y] == 'S') cnt++;
		}
	}
	if (cnt >= 4) return true;
	else return false;
}

void dfs(int index, int cnt) {
    // 7명이 되면 체크
	if (cnt == 7) {
		for (int i = 0; i < 25; i++) {
			if (count() && pick[i]) {
				if (isAdj(i / 5, i % 5)) {
					ans++;
					break;
				}
			}
		}
		return;
	}
    
    // [0][0] ~ [4][4] 중 하나 고름
	for (int i = index; i < 25; i++) {
		if (pick[i]) continue;
		pick[i] = 1;
		dfs(i, cnt + 1);
		pick[i] = 0;
	}
}


int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	dfs(0, 0);
	cout << ans;
}