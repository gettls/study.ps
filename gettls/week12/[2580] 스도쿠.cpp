#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)
int arr[9][9];
vector<pair<int, int>> list;


bool check(int x, int y, int val) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][y] == val) return false;
		if (arr[x][i] == val) return false;
	}
	int x1 = (x / 3) * 3, x2 = x1 + 3;
	int y1 = (y / 3) * 3, y2 = y1 + 3;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (arr[i][j] == val) return false;
		}
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == list.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {
		int x = list[cnt].first;
		int y = list[cnt].second;
		if (check(x, y, i)) {
			arr[x][y] = i;
			dfs(cnt + 1);
			arr[x][y] = 0;
		}
	}
}

int main() {
	for(int i=0;i<9;i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) list.push_back({ i,j });
		}

	dfs(0);

}