#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b }); // pay, day
	}
	sort(v.begin(), v.end(), cmp);
	priority_queue<int> pq;
	int res = 0;
	for (int i = n, j = 0; i >= 1; i--) {
		while (j < n && v[j].second >= i) {
			pq.push(v[j++].first);
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
}