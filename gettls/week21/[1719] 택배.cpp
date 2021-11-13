#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int n, m, INF = 987654321;
vector<vector<pair<int, int>>> arr;
int d[201], res[201], pre[201];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[cur] < dist) continue;
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextDist = dist + arr[cur][i].second;
			if (d[next] > nextDist) {
				d[next] = nextDist;
				pq.push({ -nextDist ,next });
				pre[next] = cur;
			}
		}
	}

	// pre [i] : 노드 i 의 이전 출발지를 기록
	// res [i] : pre 를 역행하며 start 까지 도달
	for (int i = 1; i <= n; i++) {
		if (i == start) continue;
		if (pre[i] == start) {
			res[i] = i; continue;
		}
		int p = pre[i];
		while (p != start) {
			res[i] = p;
			p = pre[p];
		}
	}

}

int main() {
	cin >> n >> m;

	arr.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		arr[a].push_back({ b,w });
		arr[b].push_back({ a,w });
	}

	for (int i = 1; i <= n; i++) {
		fill(d, d + n + 1, INF);
		d[i] = 0;
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			if (i == j) { printf("- "); continue; }
			printf("%d ", res[j]);
		}
		printf("\n");
	}

}