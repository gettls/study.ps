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

int n, id;
vector<vector<int>> SCC;
vector<int> arr;
vector<int> d, finished;
stack<int> s;
int dfs(int x) {
	d[x] = ++id;
	s.push(x);
	int parent = d[x];
	int y = arr[x];
	if (d[y] == 0) parent = min(parent, dfs(y));
	else if (!finished[y]) parent = min(parent, d[y]);
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = 1;
			if (x == t) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		arr.resize(n + 1, 0);
		d.resize(n + 1, 0);
		finished.resize(n + 1, 0);

		fill(arr.begin(), arr.end(), 0);
		fill(d.begin(), d.end(), 0);
		fill(finished.begin(), finished.end(), 0);

		vector<vector<int>> t;
		SCC.swap(t);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}
		int cnt = 0;

		for (int i = 0; i < SCC.size(); i++) {
			if (SCC[i].size() == 1) {
				if (arr[SCC[i][0]] != SCC[i][0]) cnt++;
			}
		}
		cout << cnt << "\n";
	}
}