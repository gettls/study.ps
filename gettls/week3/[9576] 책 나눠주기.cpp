#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 1001
#pragma warning (disable:4996)

using namespace std;

int n, m;
vector<int> arr[MAX];
bool c[MAX];
int d[MAX];

bool dfs(int m) {
	for (int i = 0; i < arr[m].size(); i++) {
		int x = arr[m][i];
		if (c[m] == 0) c[m] = 1;
		if (d[x] == 0) {
			d[x] = m;
			return true;
		}
		else if (d[x] != 0 && c[d[x]] == 0) {
			if (dfs(d[x])) {
				d[x] = m;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			for (int j = a; j <= b; j++) {
				arr[i].push_back(j);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			fill(c, c + MAX, false);
			if (dfs(i)) cnt++;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= m; i++) {
			arr[i].clear();
		}
		fill(d, d + MAX, 0);
	}
}