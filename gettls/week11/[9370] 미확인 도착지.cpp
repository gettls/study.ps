#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#pragma warning (disable:4996)
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> arr;

int INF = 2e9;
int n, m, t;
int s, g, h;
vector<int> dijkstra(int start) {
	vector<int> d(n + 1, INF);
	d[start] = 0;
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
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
	return d;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t; // 교차로, 도로, 목적지
		cin >> s >> g >> h; // 출발지, 경유지 (g,h)
		vector<vector<pair<int, int>>>().swap(arr);
		arr.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			arr[a].push_back({ b,d });
			arr[b].push_back({ a,d });
		}
		vector<int> target;
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			target.push_back(x);
		}
 		vector<int> ds = dijkstra(s);
		vector<int> dg = dijkstra(g);
		vector<int> dh = dijkstra(h);
		set<int> res;
		int dist = INF;
		for (auto dest : target) {
			// s-> g-> h-> 목적지 의 경우
			if (ds[dest] == ds[g] + dg[h] + dh[dest]) res.insert(dest);
			// s-> h-> g-> 목적지 의 경우
			if (ds[dest] == ds[h] + dh[g] + dg[dest]) res.insert(dest);
		}
		
		for (auto i : res) cout << i << " ";
		cout << "\n";
	}
}