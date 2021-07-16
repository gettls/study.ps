#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;
typedef long long ll;

int d[1001], INF = 2e9;
int parent[1001];
int n, m, a, b, c;
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
				parent[next] = cur;
				d[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}
}

bool cmp(pair<int, int> v) {
	return v.first == b;
}

int main() {
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
        // 경로가 있는 경우 비용이 더 적다면 교체
		auto it = find_if(arr[a].begin(), arr[a].end(), cmp);
		if (it != arr[a].end()) {
			if (it->second > c) it->second = c;
		}
		else arr[a].push_back({ b,c });
	}
	fill(d, d + n + 1, INF);
	for (int i = 1; i <= n; i++) parent[i] = i;
	int x, y;
	cin >> x >> y;
	dijkstra(x);

	vector<int> s;
	int pre = y;
	while (1) {
		s.push_back(pre);
		if (pre == x) break;
		pre = parent[pre];
	}
	printf("%d\n%d\n", d[y], s.size());
	for (int i = s.size() - 1; i >= 0; i--) {
		printf("%d ", s[i]);
	}
}