#include <string>
#include <vector>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n, m, r;
int item[101], d[101];
vector<vector<pair<int, int>>> v;

void dijkstra(int start) {
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[cur] < dist) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDist = dist + v[cur][i].second;
			if (d[next] > nextDist) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
}

int main() {
	cin >> n >> m >> r;
	v.resize(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> item[i + 1];
	}

	for (int i = 0; i < r; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[j] = 987654321;
		dijkstra(i);
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (d[j] <= m) sum += item[j];
		}
		ans = max(ans, sum);
	}

	cout << ans;
}