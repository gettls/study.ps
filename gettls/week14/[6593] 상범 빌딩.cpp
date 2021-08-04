#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning (disable:4996)
int L, R, C;
char arr[30][30][30];
int d[30][30][30];
int dx[] = { -1,0,1 }, dy[] = { 0,0,-1,1 }, dz[] = { 1,-1,0,0 };

struct Point {
	int x, y, z;
};
Point s, e;

void bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ s.x, {s.y, s.z} });
	d[s.x][s.y][s.z] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first, z = q.front().second.second;
		q.pop();
		for (int i = 0; i < 3; i++) {// for x
			int nx = x + dx[i];
			if (nx < 0 || nx >= L) continue;
			if (arr[nx][y][z] != '#') {
				if (d[nx][y][z] > d[x][y][z] + 1) {
					d[nx][y][z] = d[x][y][z] + 1;
					q.push({ nx,{y,z} });
				}
			}
		}

		for (int i = 0; i < 4; i++) { // for y,z
			int ny = y + dy[i], nz = z + dz[i];
			if (ny < 0 || nz < 0 || ny >= R || nz >= C) continue;
			if (arr[x][ny][nz] != '#') {
				if (d[x][ny][nz] > d[x][y][z] + 1) {
					d[x][ny][nz] = d[x][y][z] + 1;
					q.push({ x,{ny,nz} });
				}
			}
		}

	}
}


int main() {
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
			{
				fill(d[i][j], d[i][j] + C, 0);
			}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] != '#') d[i][j][k] = 1e9;

					if (arr[i][j][k] == 'S') {
						s.x = i, s.y = j, s.z = k;
					}
					if (arr[i][j][k] == 'E') {
						e.x = i, e.y = j, e.z = k;
					}
				}
			}
		}
		bfs();
		if (d[e.x][e.y][e.z] == 1e9) cout << "Trapped!\n";
		else printf("Escaped in %d minute(s).\n", d[e.x][e.y][e.z]);
	}
}