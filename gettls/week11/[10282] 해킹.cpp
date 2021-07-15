#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;
typedef long long ll;

ll d[10000], INF = 2e9;
vector<vector<pair<int, int>>> arr;
void dijkstra(int start) { 
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		ll dist = -pq.top().first;
		pq.pop();
		if (dist < d[cur]) continue;
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			ll nextDist = arr[cur][i].second + dist;
			if (d[next] > nextDist) {
				d[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, e, c;
		cin >> n >> e >> c;
		arr.resize(n + 1);
		fill(d, d + n + 1, INF);
		for (int i = 0; i < e; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			arr[b].push_back({ a,s });
		}
		dijkstra(c);
		arr.clear();
		ll cnt = 0, res = -1;
		for (int i = 1; i <= n; i++) {
			if (d[i] == INF) continue;
			if (d[i] > res) res = d[i];
			cnt++;
		}
		cout << cnt << " " << res << "\n";
	}
}