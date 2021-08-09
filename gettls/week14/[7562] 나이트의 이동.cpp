#include <string>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int t, l;
int v[300][300];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,1,-1 };
void bfs(int a, int b) {
	queue<pair<int,int>> q;
	q.push({ a,b });
	v[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if (v[nx][ny] > v[x][y] + 1) {
				v[nx][ny] = v[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}


int main() {
	cin >> t;
	while (t--) {
		cin >> l;
		int tx, ty, px, py;
		cin >> tx >> ty; // 목적지
		cin >> px >> py; // 위치
		for (int i = 0; i < l; i++) fill(v[i], v[i] + l, 1e9);
		bfs(px, py);
		cout << v[tx][ty] << "\n";
	}

 }
