#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int n, k;
int v[100001];

void bfs() {
	queue<pair<int,int>> q;
	q.push({ n,0 });
	v[n] = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur-1 >=0 && v[cur - 1] > v[cur] + 1) {
			v[cur - 1] = cnt + 1;
			q.push({ cur - 1, cnt + 1 });
		}
		if (cur+1 <= 100000 && v[cur + 1] > v[cur] + 1) {
			v[cur + 1] = cnt + 1;
			q.push({ cur + 1, cnt + 1 });
		}
		if (cur*2 <= 100000 && v[cur * 2] > v[cur] + 1) {
			v[cur * 2] = cnt + 1;
			q.push({ cur * 2, cnt + 1 });
		}
	}

}


int main() {
	cin >> n >> k;
	fill(v, v + 100001, 1e9);
	bfs();
	cout << v[k];
 }
