#include <string>
#include <vector>
#include <iostream>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

int n, m;
int arr[500][500];

int tet[19][4][2] = {
	{{0,0},{0,1},{0,2},{0,3}}, // ㅡ
	{{0,0},{1,0},{2,0},{3,0}}, // ㅣ 

	{{0,0},{0,1},{1,0},{1,1}}, // ㅁ

	// L
	{{0,0},{1,0},{2,0},{0,1}},
	{{0,0},{0,1},{1,1},{2,1}},
	{{0,0},{1,0},{0,1},{0,2}},
	{{0,0},{0,1},{0,2},{1,2}},
	{{0,0},{1,0},{2,0},{2,1}},
	{{0,0},{1,0},{2,0},{2,-1}},
	{{0,0},{1,0},{1,1},{1,2}},
	{{0,0},{1,0},{1,-1},{1,-2}},


	// z
	{{0,0},{1,0},{1,1},{2,1}},
	{{0,0},{0,1},{-1,1},{-1,2}},
	{{0,0},{1,0},{1,-1},{2,-1}},
	{{0,0},{0,1},{1,1},{1,2}},

	// ㅗ
	{{0,0},{0,1},{1,1},{0,2}},
	{{0,0},{0,1},{-1,1},{0,2}},
	{{0,0},{1,0},{2,0},{1,1}},
	{{0,0},{1,0},{2,0},{1,-1}}
};

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

int sol(int idx) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + tet[idx][k][0];
				int y = j + tet[idx][k][1];
				if (!isRange(x, y)) break;
				sum += arr[x][y];
			}
			ret = max(ret, sum);
		}
	}
	return ret;
}



int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < 19; i++) {
		ans = max(sol(i), ans);
	}
	cout << ans;
}