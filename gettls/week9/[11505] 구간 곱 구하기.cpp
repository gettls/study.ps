#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
#define num 1000000007 

vector<ll> tree;
ll v[1000001];

ll init(int s, int e, int n) {
	if (s == e) return tree[n] = v[s];
	int mid = (s + e) / 2;
	return tree[n] = init(s, mid, n * 2) * init(mid + 1, e, n * 2 + 1) % num;
}

ll find(int s, int e, int l, int r, int n) {
	if (r<s || l>e) return 1;
	if (l <= s && e <= r) return tree[n];
	int mid = (s + e) / 2;
	return find(s, mid, l, r, n * 2) * find(mid + 1, e, l, r, n * 2 + 1) % num;
}

void mod(int s, int e, int n, int index, int to) {
	if (index<s || index >e) return;
	
	if (s != e) {
		int mid = (s + e) / 2;
		mod(s, mid, n * 2, index, to);
		mod(mid + 1, e, n * 2 + 1, index, to);
	}
	if (s == e) tree[n] = to;
	else tree[n] = tree[n * 2] * tree[n * 2 + 1] % num;
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> v[i];
	tree.resize(n * 4);
	init(0, n-1, 1);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a=1: mod, a=2: output
		if (a == 1) {
			mod(1, n, 1, b, c);
		}
		else {
			ll ret = find(1, n, b, c, 1);
			cout << ret << "\n";
		}
	}
}