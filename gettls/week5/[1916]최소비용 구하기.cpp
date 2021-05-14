#include<stdio.h>
#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;

int n, m;
vector<pair<int, int>> v[1001]; // dist, dest
int d[1001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq; // dist, node
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[cur] < dist) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].second;
			int nextDist = dist + v[cur][i].first;
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}
}
 

int main(){
	int start, end;
	scanf("%d%d", &n, &m);
	fill(d, d + n+1, 1e9);
	for (int i = 0; i < m; i++) {
		int s, e, dist;
		scanf("%d%d%d", &s, &e, &dist);
		v[s].push_back({ dist,e });
	}

	scanf("%d%d", &start, &end);
	dijkstra(start);
	printf("%d", d[end]);
}