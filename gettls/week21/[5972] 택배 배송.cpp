#include <string>
#include <vector>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int n, m;
vector<vector<pair<int, int>>> v;
vector<int> d;
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
}

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	d.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}
	fill(d.begin(), d.end(), 987654321);

	dijkstra(1);

	cout << d[n];
}