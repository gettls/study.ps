#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int INF = 2e9;
vector<vector<pair<int, int>>> arr;
vector<int> d; 

void dijkstra(int start) {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[cur] < dist) continue;
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextDist = arr[cur][i].second + dist;
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
}

int main() {
	int V, E, K;
	cin >> V >> E >> K;
	arr.resize(V+1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ v,w });
	}
	d.resize(V + 1);
	fill(d.begin(), d.end(), INF);
	dijkstra(K);
	d[K] = 0;
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}
}