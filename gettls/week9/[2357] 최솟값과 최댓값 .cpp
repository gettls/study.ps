#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

vector<ll> min_tree, max_tree;
ll v[100001];

ll min_init(int s, int e, int n) {
	if (s == e) return min_tree[n] = v[s];
	int mid = (s + e) / 2;
	return min_tree[n] = min(min_init(s, mid, n * 2), min_init(mid + 1, e, n * 2 + 1));
}

ll max_init(int s, int e, int n) {
	if (s == e) return max_tree[n] = v[s];
	int mid = (s + e) / 2;
	return max_tree[n] = max(max_init(s, mid, n * 2), max_init(mid + 1, e, n * 2 + 1));
}

ll min_find(int s, int e, int l, int r, int n) {
	if (r < s || l > e) return 2e9;
	if (l <= s && e <= r) return min_tree[n];
	int mid = (s + e) / 2;
	return min(min_find(s, mid, l, r, n * 2), min_find(mid + 1, e, l, r, n * 2 + 1));
}

ll max_find(int s, int e, int l, int r, int n) {
	if (r < s || l > e) return -2e9;
	if (l <= s && e <= r) return max_tree[n];
	int mid = (s + e) / 2;
	return max(max_find(s, mid, l, r, n * 2), max_find(mid + 1, e, l, r, n * 2 + 1));
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> v[i];
	min_tree.resize(4 * n);
	max_tree.resize(4 * n);
	min_init(0, n - 1, 1);
	max_init(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		printf("%lld %lld\n", min_find(1, n, a, b, 1), max_find(1, n, a, b, 1));
	}
}