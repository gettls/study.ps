#include<iostream>
#include<queue>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
 
int n, m, x;
int dgo[1001], dback[1001];
vector<pair<int, int>> go[1001], back[1001]; // 도착점, 거리

void djikstra(int start, vector<pair<int,int>> v[], int flag) {
	int d[1001];
	fill(d, d + n + 1, 1e9);
	priority_queue<pair<int, int>> pq; // 거리, 정점
	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDist = v[cur][i].second + dist;
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}
	if (flag)memcpy(dgo, d, sizeof(d));
	else memcpy(dback, d, sizeof(d));
}


int main() {
	cin >> n >> m >> x;
	 
	for (int i = 0; i < m; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		go[s].push_back({ e,d });
		back[e].push_back({ s,d });
	}
	djikstra(x, go,1);
	djikstra(x, back, 0);
	int max = -1;
	for (int i = 1; i <= n; i++) {
		int d = dgo[i] + dback[i];
		if (d > max) max = d;
	}
	cout << max;
}