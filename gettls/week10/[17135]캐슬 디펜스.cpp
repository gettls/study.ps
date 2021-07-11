#include<iostream>
#include<stack>
#include<vector>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
int n, m, d;
int arr[15][15], tmp[15][15];
vector<int> v;

int move() {
	int cnt = 0;
	// 적군 이동
	for (int i = n - 1; i > 0; i--) {
		int ttmp[15];
		memcpy(ttmp, tmp[i - 1], sizeof(tmp[i]));
		memcpy(tmp[i], ttmp, sizeof(ttmp));
	}
	fill(tmp[0], tmp[0] + m, 0);
	return cnt;
}

void targeting(int a_pos, vector<pair<int,int>>* target) {
	stack<pair<int, int>> t;
	int min = 2e9, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 1) {
				int dist = abs(a_pos - j) + (n - i);
				if (dist < min) {
					min = dist;
					t.push({ i,j });
				} // 가까운거 찾기
				else if (dist == min) {
					int x = t.top().first, y = t.top().second;
					if (j < y) t.push({ i,j });
				} // 거리가 같으면 왼쪽에 있는거 넣기
			}
		}
	}
	if (!t.empty()) {
		int dist = abs(a_pos - t.top().second) + (n - t.top().first);
		if (d >= dist) {
			target->push_back(t.top());
		}
	}
}

int sol() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		vector<pair<int,int>> target;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == 1) targeting(j, &target);
		}
		for (int j = 0; j < target.size(); j++) {
			if (tmp[target[j].first][target[j].second]) {
				tmp[target[j].first][target[j].second] = 0;
				cnt++;
			}
		}
		move();
	}
	return cnt;
}

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	v.resize(m);
	for (int i = m - 3; i < m; i++) v[i] = 1;
	int max = -1;
	do {
		memcpy(tmp, arr, sizeof(arr));
		int cnt = sol();
		if (cnt > max) max = cnt;
	} while (next_permutation(v.begin(), v.end()));
	cout << max;
}
