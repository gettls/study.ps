#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
vector<ll> v, tree;

ll init(int n, int s, int e) {
	if (s == e) return tree[n] = v[s];
	int mid = (s + e) / 2;
	return tree[n] = init(n * 2, s, mid) + init(n * 2 + 1, mid + 1, e);
}

void update(int n, int s, int e, int index, ll diff) {
	if (index<s || index > e) return;
	tree[n] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(n * 2, s, mid, index, diff);
		update(n * 2 + 1, mid + 1, e, index, diff);
	}
	return;
}

ll sum(int l, int r, int s, int e, int n) {
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) return tree[n];
	int mid = (s + e) / 2;
	return sum(l, r, s, mid, n * 2) + sum(l, r, mid + 1, e, n * 2 + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}
	tree.resize(n * 4);
	init(1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c; // a=1 : update, a=2 : sum
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - v[b - 1];
			v[b - 1] = c;
			update(1, 1, n , b, diff);
		}
		else if (a == 2) {
			ll ret = sum(b , c, 1, n, 1);
			cout << ret << '\n';
		}
	}
}