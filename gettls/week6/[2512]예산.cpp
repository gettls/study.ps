#include<algorithm>
#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
int n, m;
vector<int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	cin >> m;
	sort(v.begin(), v.end());
	long long s = v[0], e = v[n - 1], res = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] < mid) sum += v[i];
			else sum += mid;
		}

		if (sum <= m) {
			res = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	if (res == 0) res = m / n;
	cout << res;
}