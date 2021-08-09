#include <string>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)


int t, n, k, w;
vector<vector<int>> v;
int cost[1001], in[1001], totalCost[1001];
int ret;
void bfs() {
	while (1) {
		queue<int> q;
		if (in[w] == 0) return;
		
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.push(i);
				in[i] = -1;
			}
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
				totalCost[next] = max(totalCost[next], totalCost[cur] + cost[next]);
				in[next]--;
			}
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		fill(cost, cost + n + 1, 0);
		vector<vector<int>> t(n + 1);
		v.swap(t);
		for (int i = 1; i <= n; i++) {
			int c;
			cin >> c;
			cost[i] = c;
			totalCost[i] = c;
		}
		fill(in, in + n + 1, 0);
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			in[b]++;
		}
		cin >> w;
		bfs();
		cout << totalCost[w] << "\n";
	}
}
