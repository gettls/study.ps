#include <string>
#include <vector>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;


int t, n, m, MAX = 987654321;
vector<vector<pair<int, int>>> v;
vector<int> d, d_sum;
void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[cur] < dist) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDist = dist + v[cur][i].second;
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}

	for (int i = 1; i <= n; i++) d_sum[i] += d[i];
}

int main() {
	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> n >> m;
		v.resize(n + 1);
		d.resize(n + 1);
		d_sum.resize(n + 1);
		fill(d_sum.begin(), d_sum.end(), 0);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			fill(d.begin(), d.end(), MAX);
			int x; cin >> x;
			dijkstra(x);
		}

		int ans = MAX, idx = 1;
		for (int i = 1; i <= n; i++) {
			if (ans > d_sum[i]) {
				idx = i;
				ans = d_sum[i];
			}
		}
		cout << idx << "\n";
		vector<vector<pair<int, int>>> a;
		v = a;
	}
}