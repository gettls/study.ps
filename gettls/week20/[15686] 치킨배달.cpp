#include <string>
#include <vector>
#include <iostream>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

int N, M, arr[50][50], ans = 1e9;
vector<pair<int, int>> dst, chicken;
vector<int> idx;
// 치킨거리 계산
int dist(pair<int, int> pos) {
	int x = pos.first, y = pos.second;
	int ret = 1e9;
	for (int i = 0; i < idx.size(); i++) {
		if (idx[i] == 0) continue;
		int t_x = chicken[i].first, t_y = chicken[i].second;
		int dist = abs(t_x - x) + abs(t_y - y);
		if (ret > dist) ret = dist;
	}
	return ret;
}

void backtracking(int cnt, int index) {
	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < dst.size(); i++) {
			sum += dist(dst[i]);
		}
		if (sum < ans) ans = sum;
	}

	for (int i = index; i < idx.size(); i++) {
		idx[i] = 1;
		backtracking(cnt + 1, i + 1);
		idx[i] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) dst.push_back({ i,j });
			if (arr[i][j] == 2) {
				chicken.push_back({ i,j });
				idx.push_back(0);
			}
		}
	}
	backtracking(0, 0);
	cout << ans;
}