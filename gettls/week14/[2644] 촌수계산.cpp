#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n, m;
int x, y;
vector<vector<int>> arr;
int v[101];
int dfs(int t, int cnt) {

	if (t == y) {
		cout << cnt;
		exit(0);
	}

	for (int i = 0; i < arr[t].size(); i++) {
		if (v[arr[t][i]]) continue;
		v[arr[t][i]] = 1;
		dfs(arr[t][i], cnt + 1);
		v[arr[t][i]] = 0;
	}
	return -1;
}

int main() {
	cin >> n;
	cin >> x >> y;
	cin >> m;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; // 부모 자식
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	cout << dfs(x, 0);
}
