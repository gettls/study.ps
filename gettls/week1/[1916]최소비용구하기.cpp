#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9
int n,m;
vector<vector<pair<int, int>>> v; // (도착지, 비용)

int main() {
	cin >> n >> m;
	v.assign(n + 1, vector<pair<int, int>>(0, { 0,0 }));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	int from, to;
	cin >> from >> to;
	int d[1001];
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}


	priority_queue<pair<int, int>> pq; // 비용,도착지
	pq.push({ 0, from });
	d[from] = 0;

  	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[now] < dist) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextDist = v[now][i].second + dist;
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}

	cout << d[to];
}