#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int INF = 2e9;
int n, e;

class Edge {
public:
	int node[2];
	int dist;
	Edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}
	bool operator < (Edge& edge) { //정렬 기준
		return this->dist > edge.dist;
	}
};

vector<int> parent;


int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	cin >> n >> e;
	vector<Edge> arr;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(Edge(a, b, c));
	}
	sort(arr.begin(), arr.end());
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;

	int v1, v2, x, y;
	cin >> v1 >> v2;
	
	int min = INF;
	// Kruskal
	// 내림차순으로 정렬
	// 가중치를 내림차순으로 확인하다가 v1과 v2가 뚫리는 순간
	// 즉, v1과 v2의 부모가 같아지는 순간은 v1<->v2 가중치가 최대인 순간이다
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			unionParent(arr[i].node[0], arr[i].node[1]);
		}
		if (findParent(v1, v2)) {
			cout << arr[i].dist;
			break;
		}
	}

}