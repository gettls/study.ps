#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int INF = 2e9;
vector<vector<pair<int, int>>> arr;
int n, e;

vector<int> dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	vector<int> d(n + 1, INF);
	d[start] = 0;
	while (!pq.empty())
	{
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
	return d;
}

int main() {
	cin >> n >> e;
	arr.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<int> t = dijkstra(1);
	vector<int> t1 = dijkstra(v1);
	vector<int> t2 = dijkstra(v2);

	int res = min(t[v1] + t1[v2] + t2[n], t[v2] + t2[v1] + t1[n]);
	if (t[v1] == INF || t1[v2] == INF 
		|| t2[v1] == INF || t[v2] == INF) res = -1;
	cout << res;
}