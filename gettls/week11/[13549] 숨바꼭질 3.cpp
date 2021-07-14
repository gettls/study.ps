#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100000
int d[MAX];
void dfs(int n, int k) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) return;
		for (int i = 0; x*pow(2,i) <= MAX; i++) {
			int next = x * pow(2, i);
			if (d[next] != -1) continue;
			d[next] = d[x];
			q.push(next);
		}
		if (d[x - 1] == -1 && x - 1 >= 0) {
			d[x - 1] = d[x] + 1;
			q.push(x - 1);
		}
		if (d[x + 1] == -1 && x + 1 <= MAX) {
			d[x + 1] = d[x] + 1;
			q.push(x + 1);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
    // fill 의 경우 두번째 인자의 -1 까지 값을 넣어준다
	fill(d, d + MAX + 1, -1);
	d[n] = 0;
	dfs(n,k);
	cout << d[k];
}